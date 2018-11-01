from __future__ import absolute_import, unicode_literals
from .celery import app

# these are example tasks
# http://docs.celeryproject.org/en/latest/getting-started/first-steps-with-celery.html

@app.task
def add(x, y):
    return x + y


@app.task
def mul(x, y):
    return x * y


@app.task
def xsum(numbers):
    return sum(numbers)