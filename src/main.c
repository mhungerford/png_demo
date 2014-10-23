#include <pebble.h>

// PNG support
// Includes Grayscale support for 1 bit (B&W)
#include "png.h"

Window* my_window = NULL;

//Image Display
BitmapLayer* bitmap_layer = NULL;
GBitmap* gbitmap = NULL;

static void window_load(Window *window) {
  Layer *window_layer = window_get_root_layer(window);
  GRect bounds = layer_get_bounds(window_layer);
  
  //Add layers from back to front (background first)

  //Create bitmap layer for background image
  bitmap_layer = bitmap_layer_create(bounds);
  //Add bitmap_layer to window layer
  layer_add_child(window_layer, bitmap_layer_get_layer(bitmap_layer));

  //Load initial bitmap image
  gbitmap = gbitmap_create_with_png_resource(RESOURCE_ID_IMAGE_ROBOT);
  bitmap_layer_set_bitmap(bitmap_layer, gbitmap);
}

static void window_unload(Window *window) {
  gbitmap_destroy(gbitmap);
}



void handle_init(void) {
  my_window = window_create();
  window_set_fullscreen(my_window, true);
  window_set_window_handlers(my_window, (WindowHandlers) {
    .load = window_load,
    .unload = window_unload,
  });

  window_stack_push(my_window, false);
}

void handle_deinit(void) {
    bitmap_layer_destroy(bitmap_layer);
	  window_destroy(my_window);
}


int main(void) {
	  handle_init();
	  app_event_loop();
	  handle_deinit();
}
