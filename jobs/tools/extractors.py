from re import compile as re_compile

from offers.models import Category

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

    def category_hyperlink_filter(self, tag):
        return self.hyperlink_filter(tag, self.regex['category_pagination'])

    def extract_pagination(self, tag, category_id=None):
        # result: pagination
        href = tag['href']
        regex = re_compile(self.regex['category_pagination'])
        match = regex.match(href)
        if category_id and int(match.group(2)) != category_id:
            return 0
        return int(match.group(3))

    def find_max_pagination(self, limit=None):
        pass