from re import compile as re_compile

from offers.models import Category
from jobs.models import Job
from jobs.tools.connector import Connector

class HomepageExtractor(Connector):

    def category_hyperlink_filter(self, tag):
        return self.hyperlink_filter(tag, self.regex['category'])

    def extract_category_from_tag(self, tag):
        # [URL, full_name_category, category_id, parent_categories_count]
        # ['https://vubu.pl/pol_m_DLA-NIEJ_Odziez-damska-604.html', 'DLA-NIEJ_Odziez-damska', 604, 2]
        href = tag['href']
        regex = re_compile(self.regex['category'])
        match = regex.match(href)
        category_id = int(match.group(2))
        category_full_name = match.group(1)
        depth = len(category_full_name.split("_"))
        proper_url = self.patterns['category'] % (match.group(1), category_id) # cleans GET parameters
        return [proper_url, category_full_name, category_id, depth]

    def find_all_categories_list(self):
        connection_result = self.make_connection(self.patterns['homepage'])
        if not connection_result[0]:
            return []
        soup = self.soup_result(connection_result[1])
        found_tags = soup.find_all(self.category_hyperlink_filter)
        tags_list = []
        tags_ids = []
        for tag in found_tags:
            data = self.extract_category_from_tag(tag)
            if data[2] in tags_ids:
                continue
            tags_ids.append(data[2])
            tags_list.append(data)
        return tags_list

    def find_last_categories_list(self):
        all_categories = self.find_all_categories_list()
        result = []
        for category in all_categories:
            if category[2] >= 3:
                result.append(category)
        return result

    def save_category_object(self, data):
        vubu_id = data[2]
        # getting proper Category object
        category_object = Category.objects.filter(vubu_id=vubu_id)
        if category_object.count() > 0:
            category_object = category_object[0]
        else:
            category_object = Category()
            category_object.vubu_id = vubu_id

        # here is the code about inserting arguments
        # [URL, full_name_category, category_id, parent_categories_count]
        # ['https://vubu.pl/pol_m_DLA-NIEJ_Odziez-damska-604.html', 'DLA-NIEJ_Odziez-damska', 604, 2]
        # so:
            # data[0] - URL
            # data[1] - full_name_category
            # data[2] - vubu_id (already created!)
            # data[3] - parent_categories_count (1 - top parent)
        # example:
        # category_object.vubu_id = data[2]
        category_object.short_name = " "
        category_object.full_name = " "
        category_object.url = "http://www.google.pl"

        category_object.save()
        return

    def find_and_create_categories(self):
        categories_list = self.find_all_categories_list()
        for category_data in categories_list:
            self.save_category_object(category_data)
        return


class CategoryPageExtractor(Connector):

    def category_pagination_hyperlink_filter(self, tag):
        return self.hyperlink_filter(tag, self.regex['category_pagination'])

    def product_hyperlink_filter(self, tag):
        return self.hyperlink_filter(tag, self.regex['product'])

    def extract_pagination(self, tag, category_id=None):
        # result: pagination
        href = tag['href']
        regex = re_compile(self.regex['category_pagination'])
        match = regex.match(href)
        if category_id and int(match.group(2)) != category_id:
            return 0
        return int(match.group(3))

    def extract_product_url(self, tag):
        href = tag['href']
        regex = re_compile(self.regex['product'])
        match = regex.match(href)
        product_id = int(match.group(1))
        product_title = match.group(2)
        return self.patterns['product'] % (product_id, product_title)

    def find_max_pagination(self, session_object):
        category_url = session_object.category_url
        connection_result = self.make_connection(category_url)
        if not connection_result[0]:
            return 0
        soup = self.soup_result(connection_result[1])
        found_tags = soup.find_all(self.category_pagination_hyperlink_filter)
        highest_pagination = 0
        for tag in found_tags:
            new_pagination = self.extract_pagination(tag)
            if new_pagination > highest_pagination:
                highest_pagination = new_pagination
        return highest_pagination

    def create_unique_job(self, session_object, url_tag):
        job_url = self.extract_product_url(url_tag)
        if Job.objects.filter(url=job_url, session=session_object).count() > 0:
            return 0
        job = Job()
        job.url = job_url
        job.session = session_object
        job.status = Job.STATUS_INITIATED
        job.save()
        return 1

    def extract_product_url_tags(self, session_object, pagination=0):
        url = session_object.category_url
        if pagination > 0:
            url = self.patterns['url_pagination'] % (url, pagination)
        connection_result = self.force_connection(url)
        soup = self.soup_result(connection_result[0])
        found_tags = soup.find_all(self.product_hyperlink_filter)
        return found_tags

    def create_jobs(self, session_object):
        max_pagination = self.find_max_pagination(session_object)
        max_pagination += 1

        jobs_count = 0
        jobs_limit = session_object.objects_limit
        no_limit = (jobs_limit <= 0)
        pagination = 0

        while (pagination < max_pagination) and (no_limit or jobs_count < jobs_limit):
            found_tags = self.extract_product_url_tags(session_object, pagination)
            itr = 0
            itr_max = len(found_tags)
            while (itr < itr_max) and (no_limit or jobs_count < jobs_limit):
                tag = found_tags[itr]
                jobs_count += self.create_unique_job(session_object, tag)
                itr += 1
            pagination += 1

        return jobs_count
