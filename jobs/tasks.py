# -*- coding: UTF-8 -*-

from __future__ import absolute_import, unicode_literals
from .celery import app

# please don't import anything except inside functions
# this is mainly because of loop inport problems

#  example task:
# @app.task
# def add(x, y):
#     return x + y