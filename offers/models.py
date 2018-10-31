# -*- coding: UTF-8 -*-

from django.db import models


class Category(models.Model):

    vubu_id = models.IntegerField()
    short_name = models.CharField(max_length=15)
    full_name = models.CharField(max_length=63)
    url = models.URLField()

    def __str__(self):
        return self.full_name


class Product(models.Model):

    url = models.URLField()
    vubu_id = models.IntegerField()

    title = models.CharField(max_length=63)
    category = models.ForeignKey(Category,
            on_delete=models.CASCADE, related_name="products")

    code = models.CharField(max_length=7)
    code_detail = models.CharField(max_length=31)
    series = models.CharField(max_length=7)
    description = models.TextField(blank=True, null=True)

    price_old = models.DecimalField(max_digits=7,
            decimal_places=2, null=True, blank=True)
    price_new = models.DecimalField(max_digits=7,
            decimal_places=2, null=True, blank=True)
    available_sizes = models.CharField(max_length=63)

    def __str__(self):
        return "%s (%s)" % (self.title, self.category.short_name)


class Photo(models.Model):

    product = models.ForeignKey(Product,
            on_delete=models.CASCADE, related_name="photos")
    url = models.URLField()

    def __str__(self):
        return "%s (%d)" % (self.product.title, self.pk)


class ClotheSize(models.Model):

    name = models.CharField(max_length=7)
    product = models.ForeignKey(Product,
            on_delete=models.CASCADE, related_name="sizes")

    def __str__(self):
        return "%s (%s)" % (self.product.title, self.name)


class ClotheSizeDetail(models.Model):

    size = models.ForeignKey(ClotheSize,
            on_delete=models.CASCADE, related_name="details")
    title = models.CharField(max_length=31)
    value = models.IntegerField(blank=True, null=True)

    def __str__(self):
        return "%s: %s" % (self.title, self.value)

