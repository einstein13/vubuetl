from django.core.management.base import BaseCommand, CommandError

from jobs.tools.extractors import HomepageExtractor

class Command(BaseCommand):
    help = 'Saves all categories'

    def handle(self, *args, **options):
        he = HomepageExtractor()
        array = he.find_all_categories_list()
        for el in array:
            print(el)
        return