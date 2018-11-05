from django.urls import path

from jobs.views.api import *

urlpatterns = [
]

urlpatterns = [
    path('categories-upload/', CategoriesUpload, name='api-categories-upload'),
]
