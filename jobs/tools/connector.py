from urllib.request import urlopen
from re import compile

from jobs.tools.commons import CommonData

class Connector(CommonData):

    protocole = "https://"
    domain = "vubu.pl"

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

    def pagination_hyperlink_filter(self, tag):
        return self.hyperlink_filter(tag, self.regex['category_pagination'])

    def product_hyperlink_filter(self, tag):
        return self.hyperlink_filter(tag, self.regex['product'])