# -*- coding: UTF-8 -*-

from django.views.generic import TemplateView

class Home(TemplateView):
    template_name = "home.html"

    def get_context_data(self, **kwargs):
        context = super().get_context_data(**kwargs)
        return context

class StaticData(TemplateView):
    template_name = "static_data.html"

    def get_context_data(self, **kwargs):
        context = super().get_context_data(**kwargs)
        return context

class ETL(TemplateView):
    template_name = "etl.html"

    def get_context_data(self, **kwargs):
        context = super().get_context_data(**kwargs)
        return context