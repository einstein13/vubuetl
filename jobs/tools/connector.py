from urllib.request import urlopen
from re import compile

from jobs.tools.commons import CommonData
from jobs.models import ConnectorError

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

    def push_to_errors_storage(self, error):
        ce = ConnectorError()
        ce.url = error.url
        ce.code = error.code
        ce.message = error.fp.msg
        ce.save()
        return

    def make_connection(self, url):
        new_url = self.correct_url(url)
        try:
            request = urlopen(url)
            response = request.read()
            string = response.decode("utf-8")
        except Exception as e:
            self.push_to_errors_storage(e)
            print(e)
            return [False, ""]
        return [True, string]

    def pagination_hyperlink_filter(self, tag):
        return self.hyperlink_filter(tag, self.regex['category_pagination'])

    def product_hyperlink_filter(self, tag):
        return self.hyperlink_filter(tag, self.regex['product'])