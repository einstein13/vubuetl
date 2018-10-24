from django.contrib import admin

# Register your models here.

from .models import Session, Job


class SessionAdmin(admin.ModelAdmin):
    pass

class JobAdmin(admin.ModelAdmin):
    pass

admin.site.register(Session, SessionAdmin)
admin.site.register(Job, JobAdmin)