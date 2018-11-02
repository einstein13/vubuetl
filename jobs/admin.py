from django.contrib import admin

# Register your models here.

from .models import Session, Job


class SessionAdmin(admin.ModelAdmin):
    list_display=('public_id', 'start_time', 'last_update', 'status', 'category_url')

class JobAdmin(admin.ModelAdmin):
    list_display=('url', 'session_id', 'status', 'connection_errors')

    def session_id(self, obj):
        return "%d" % (obj.session.pk, )

admin.site.register(Session, SessionAdmin)
admin.site.register(Job, JobAdmin)