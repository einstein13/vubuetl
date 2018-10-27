from django.contrib import admin

from offers.models import Category, Product, Photo,\
        ClotheSize, ClotheSizeDetail


class CategoryAdmin(admin.ModelAdmin):
    pass


class ProductAdmin(admin.ModelAdmin):
    pass


class PhotoAdmin(admin.ModelAdmin):
    pass


class ClotheSizeAdmin(admin.ModelAdmin):
    pass


class ClotheSizeDetailAdmin(admin.ModelAdmin):
    pass


admin.site.register(Category, CategoryAdmin)
admin.site.register(Product, ProductAdmin)
admin.site.register(Photo, PhotoAdmin)
admin.site.register(ClotheSize, ClotheSizeAdmin)
admin.site.register(ClotheSizeDetail, ClotheSizeDetailAdmin)