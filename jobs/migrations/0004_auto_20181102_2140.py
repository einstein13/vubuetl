# Generated by Django 2.1.2 on 2018-11-02 21:40

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('jobs', '0003_auto_20181031_2132'),
    ]

    operations = [
        migrations.AddField(
            model_name='session',
            name='automatic_etl',
            field=models.BooleanField(default=True),
        ),
        migrations.AlterField(
            model_name='session',
            name='objects_limit',
            field=models.IntegerField(default=0),
        ),
    ]