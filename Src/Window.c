#include "Internal.h"

NeptuneWindow* neptuneCreateWindow(int width, int height, const char* title) {
  NeptuneWindow* window = calloc(1, sizeof(NeptuneWindow));

  window->width = width;
  window->height = height;
  window->title = title;

  window->resizable = NEPTUNE_TRUE;
  window->shouldClose = NEPTUNE_FALSE;

  platformCreateWindow(window);

  return window;
}

void neptuneDestroyWindow(NeptuneWindow* window) {
  platformDestroyWindow(window);
}

NeptuneBool neptuneShouldWindowClose(NeptuneWindow* window) {
  return platformShouldWindowClose(window);
}
