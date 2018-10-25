from urllib.request import urlopen
from re import compile
from bs4 import BeautifulSoup

class Connector(object):

    protocole = "https://"
    domain = "vubu.pl"

    regex = {
        "category": "/pol_m_(.*)-(\d+)\.html",
        "product": "/product-pol-(\d+)-(.*)\.html"
        }

    patterns = {
        "homepage": "https://vubu.pl/",
        "category": "https://vubu.pl/pol_m_%s-%d.html",
        "category_pagination": "https://vubu.pl/pol_m_%s-%d.html?counter=%d",
        "product": "https://vubu.pl/product-pol-%d-%s.html"
    }

    # connection methods
    def correct_url(self, url):
        if url.startswith(self.protocole):
            return url
        if url.startswith(self.domain):
            return self.protocole + url
        return self.protocole + self.domain + url

    def make_connection(self, url):
        new_url = self.correct_url(url)
        request = urlopen(url)
        response = request.read()
        string = response.decode("utf-8")
        return string

    def soup_result(self, result):
        return BeautifulSoup(result, features="html.parser")

    # soup finder
    def category_hyperlink_filter(self, tag):
        if tag.name != 'a':
            return False
        if not tag.has_attr('href'):
            return False
        if not tag['href']:
            return False
        href = tag['href']
        regex = compile(self.regex['category'])
        if regex.match(href):
            return True
        return False

    # homepage processing
    def extract_category_from_tag(self, tag):
        # [URL, full_name_category, category_id, parent_categories_count]
        # ['https://vubu.pl/pol_m_DLA-NIEJ_Odziez-damska-604.html', 'DLA-NIEJ_Odziez-damska', 604, 2]
        href = tag['href']
        regex = compile(self.regex['category'])
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

