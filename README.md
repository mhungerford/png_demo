pebble-png_demo
=================

This is a port of uPNG to pebble for support of compressed images.  This will allow up to 4 times as many images stored as resources + transfer faster from the javascript/companion_app due to the smaller compressed size.  Currently Pebble images are a non-standard bitmap format called PBI, as documented here: 
https://developer.getpebble.com/2/api-reference/group___graphics_types.html#struct_g_bitmap

![golem_original](https://raw.githubusercontent.com/mhungerford/png_demo/master/robot_orig.png)|
![golem_dithered](https://github.com/mhungerford/png_demo/raw/master/resources/robot.png)

2 functions are provided in png.h
for ease of porting:

```
GBitmap* gbitmap_create_with_png_resource(uint32_t resource_id);
GBitmap* gbitmap_create_with_png_data(uint8_t *data, int data_bytes);
```

To switch from using PBI images to PNG images, update appinfo.json from type "png" to type "raw" and
replace call to gbitmap_create_with_resource with gbitmap_create_with_png_resource.

The 2nd function (_with_png_data) will convert a png transfered over appmessage as a bytearray to a gbitmap (allowing png images to be transferred from javascript/companion_apps).


Images must be pre-converted to 1-bit with sizes <= 144x168.  

The following scripts will convert images to compressed PNG 1-bit:
to_bw_png.sh
to_dithered_png.sh (includes configurable dithering)

To convert images:
./to_bw_png.sh myimage.png

golem.png
License: CC-BY 3.0
Author: Michele Bucelli (aka. Buch)
http://opengameart.org/content/mechanic-giant


