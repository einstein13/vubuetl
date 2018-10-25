from re import compile as re_compile

from bs4 import BeautifulSoup

class CommonData(object):

    regex = {
        "category": "/pol_m_(.*)-(\d+)\.html",
        "category_pagination": "/pol_m_(.*)-(\d+)\.html\?counter=(\d+)",
        "product": "/product-pol-(\d+)-(.*)\.html"
        }

    patterns = {
        "homepage": "https://vubu.pl/",
        "category": "https://vubu.pl/pol_m_%s-%d.html",
        "category_pagination": "https://vubu.pl/pol_m_%s-%d.html?counter=%d",
        "product": "https://vubu.pl/product-pol-%d-%s.html"
    }

    def soup_result(self, result):
        return BeautifulSoup(result, features="html.parser")

    # soup finder
    def hyperlink_filter(self, tag, regex_string):
        if tag.name != 'a':
            return False
        if not tag.has_attr('href'):
            return False
        if not tag['href']:
            return False
        href = tag['href']
        regex = re_compile(regex_string)
        if regex.match(href):
            return True
        return False
        