# -*- coding: UTF-8 -*-

from random import choice

from django.db import models

# Create your models here.

class Session(models.Model):

    STATUS_ERROR = 1
    STATUS_INTERRUPTED = 2

    STATUS_INITIATING = 10
    STATUS_INITIATED = 20
    STATUS_URLS_LOADING = 30 
    STATUS_URLS_LOADED = 40
    STATUS_HTML_LOADING = 50
    STATUS_HTML_LOADED = 60
    STATUS_OBJECTS_LOADING = 70
    STATUS_OBJECTS_LOADED = 80
    STATUS_CLEARING = 90
    STATUS_FINISHED = 100

    STATUSES = (
        (STATUS_ERROR, "BŁĄD"),
        (STATUS_INTERRUPTED, "Zatrzymano przetwarzanie"),
        (STATUS_INITIATING, "Inicjuję"),
        (STATUS_INITIATED, "Zainicjowano"),
        (STATUS_URLS_LOADING, "Ładuję adresy stron"),
        (STATUS_URLS_LOADED, "Adresy stron załadowane"),
        (STATUS_HTML_LOADING, "Ładuję treść stron"),
        (STATUS_HTML_LOADED, "Treść stron załadowana"),
        (STATUS_OBJECTS_LOADING, "Ładuję obiekty do bazy"),
        (STATUS_OBJECTS_LOADED, "Obiekty załadowane do bazy"),
        (STATUS_CLEARING, "Czyszczę dane"),
        (STATUS_FINISHED, "Zakończono")
        )

    # metadata
    start_time = models.DateTimeField(auto_now_add=True)
    last_update = models.DateTimeField(auto_now=True)
    stop_time = models.DateTimeField(blank=True, null=True)
    public_id = models.CharField(max_length=7, blank=True)

    # job processing
    status = models.IntegerField(choices=STATUSES)
    
    # basic settings
    category_url = models.URLField()
    objects_limit = models.IntegerField() # for <= 0 - no limit
    pagination_limit = models.IntegerField(blank=True, null=True)

    # common data
    jobs_count = models.IntegerField(blank=True, null=True)

    def save(self):
        if self.pk is None:
            self.generate_public_id()
        return super().save()

    def generate_public_id(self):
        if self.public_id:
            return self.public_id
        dictionary = "ABCDEFGHJKMNPQRSTUVWXYZ23456789"
        result = ""
        for itr in range(7):
            result += choice(dictionary)
        self.public_id = result
        return result

    def set_jobs_count(self):
        self.jobs_count = self.jobs.count()
        self.save()
        return


class Job(models.Model):

    STATUS_ERROR = 1
    STATUS_INITIATED = 10
    STATUS_HTML_LOADED = 20
    STATUS_OBJECTS_LOADED = 30

    STATUSES = (
        (STATUS_ERROR, "BŁĄD"),
        (STATUS_INITIATED, "Zainicjowano"),
        (STATUS_HTML_LOADED, "Treść stron załadowana"),
        (STATUS_OBJECTS_LOADED, "Obiekty załadowane do bazy")
        )

    # job processing
    status = models.IntegerField(choices=STATUSES)
    session = models.ForeignKey(Session, on_delete=models.CASCADE, related_name="jobs")

    # data
    url = models.URLField()
    html_data = models.TextField(blank=True, null=True)
    transformed_data = models.TextField(blank=True, null=True)