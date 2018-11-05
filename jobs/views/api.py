from json import dumps

from django.http import HttpResponse

from jobs.tools.extractors import HomepageExtractor

def jsonResponse(dictionary):
    json = dumps(dictionary)
    return HttpResponse(json)


def CategoriesUpload(request):

    result = {}

    he = HomepageExtractor()
    length = he.find_and_create_categories()
    result['categories_number'] = length

    return jsonResponse(result)
