from django.core.management.base import BaseCommand, CommandError

from jobs.tools.extractors import HomepageExtractor

class Command(BaseCommand):
    help = 'Saves all categories'

    def handle(self, *args, **options):
        he = HomepageExtractor()
        he.find_and_create_categories()
        return