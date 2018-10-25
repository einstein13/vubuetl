from re import compile as re_compile

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
        soup = self.soup_result(connection_result)
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


class CategoryPageExtractor(Connector):

    def extract_pagination(self, tag, category_id=None):
        # result: pagination
        href = tag['href']
        regex = re_compile(self.regex['category_pagination'])
        match = regex.match(href)
        if category_id and int(match.group(2)) != category_id:
            return 0
        return int(match.group(3))
        