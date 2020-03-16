#include "Internal.h"

NeptuneWindow* neptuneCreateWindow(int width, int height, const char* title) {

  assert(title != NULL);
  assert(width >= 0);
  assert(height >= 0);

  _NEPTUNE_REQUIRE_INIT;

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
  assert(window != NULL);
  _NEPTUNE_REQUIRE_INIT;

  platformDestroyWindow(window);
}

NeptuneBool neptuneWindowShouldClose(NeptuneWindow* window) {
  assert(window != NULL);
  _NEPTUNE_REQUIRE_INIT;

  return platformWindowShouldClose(window);
}

void neptuneSwapBuffers(NeptuneWindow* window) {


  platformSwapBuffers(window);
}

void neptuneMakeContextCurrent(NeptuneWindow* window) {
  assert(window != NULL);
  _NEPTUNE_REQUIRE_INIT;

  platformMakeContextCurrent(window);
}