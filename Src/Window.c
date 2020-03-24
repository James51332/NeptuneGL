#include "Internal.h"

// ---------------------------------------------------
// ---------------------------------------------------
// ----------       NEPTUNE METHODS         ----------
// ---------------------------------------------------
// ---------------------------------------------------

void insertWindowIntoGlobalList(NeptuneWindow* window) {
  if (_neptune.windowListHead == NULL) {
    _neptune.windowListHead = window;
    return;
  }

  NeptuneWindow* tracer = _neptune.windowListHead;
  while (tracer -> next != NULL)
    tracer = tracer -> next;
  tracer -> next = window;
}

// ---------------------------------------------------
// ---------------------------------------------------
// ----------      NEPTUNE PUBLIC API       ----------
// ---------------------------------------------------
// ---------------------------------------------------


NEPTUNEAPI NeptuneWindow* neptuneCreateWindow(int width, int height, const char* title) {

  assert(title != NULL);
  assert(width >= 0);
  assert(height >= 0);

  _NEPTUNE_REQUIRE_INIT_OR_RETURN(NULL);

  NeptuneWindow* window = (NeptuneWindow*) malloc(sizeof(NeptuneWindow));

  window->next = NULL;

  window->width = width;
  window->height = height;
  window->title = title;

  window->resizable = NEPTUNE_TRUE;
  window->shouldClose = NEPTUNE_FALSE;

  window->keys = (NeptuneBool *) malloc(256 * sizeof(NeptuneBool));
  memset(window->keys, NEPTUNE_FALSE, 256);

  platformCreateWindow(window);

  insertWindowIntoGlobalList(window);

  return window;
}

NEPTUNEAPI void neptuneDestroyWindow(NeptuneWindow* window) {

  assert(window != NULL);

  _NEPTUNE_REQUIRE_INIT();

  platformDestroyWindow(window);
}

NEPTUNEAPI void neptuneDestroyAllWindows() {

  _NEPTUNE_REQUIRE_INIT();

  if (_neptune.windowListHead == NULL)
    return;

  while (_neptune.windowListHead != NULL) {
    NeptuneWindow *pointer = _neptune.windowListHead -> next;
    neptuneDestroyWindow(_neptune.windowListHead);
    free(_neptune.windowListHead);
    _neptune.windowListHead = pointer;
  }
}

NEPTUNEAPI NeptuneBool neptuneWindowShouldClose(NeptuneWindow* window) {

  assert(window != NULL);

  _NEPTUNE_REQUIRE_INIT_OR_RETURN(NEPTUNE_FALSE);

  if (window->shouldClose)
    return window->shouldClose;
  else
    return NEPTUNE_FALSE;
}

// ---------------------------------------------------
// ---------------------------------------------------
// ----------      NEPTUNE GETTER API       ----------
// ---------------------------------------------------
// ---------------------------------------------------

NEPTUNEAPI void neptuneGetWindowSize(NeptuneWindow* window, int* width, int* height) {
  assert(window != NULL);

  _NEPTUNE_REQUIRE_INIT();

  if (width != NULL)
    width = &window->width;

  if (height != NULL)
    height = &window->height;
}
