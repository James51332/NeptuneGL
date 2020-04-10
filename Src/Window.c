#include "Internal.h"

// ---------------------------------------------------
// ---------------------------------------------------
// ----------       NEPTUNE METHODS         ----------
// ---------------------------------------------------
// ---------------------------------------------------

void insertWindowIntoGlobalList(NeptuneWindow *window)
{
  if (_neptune.windowListHead == NULL)
  {
    _neptune.windowListHead = window;
    return;
  }

  NeptuneWindow *tracer = _neptune.windowListHead;
  while (tracer->next != NULL)
    tracer = tracer->next;
  tracer->next = window;
}

// ---------------------------------------------------
// ---------------------------------------------------
// ----------      NEPTUNE PUBLIC API       ----------
// ---------------------------------------------------
// ---------------------------------------------------

NEPTUNEAPI NeptuneWindow *neptuneCreateWindow(int width, int height, const char *title)
{

  assert(title != NULL);
  assert(width >= 0);
  assert(height >= 0);

  _NEPTUNE_REQUIRE_INIT_OR_RETURN(NULL);

  NeptuneWindow *window = (NeptuneWindow *)malloc(sizeof(NeptuneWindow));

  window->next = NULL;

  window->initwidth = width;
  window->initheight = height;
  window->title = title;

  window->resizable = NEPTUNE_TRUE;
  window->shouldClose = NEPTUNE_FALSE;

  window->keys = (NeptuneKeyState *)malloc((NEPTUNE_KEY_LAST + 1) * sizeof(NeptuneKeyState));
  memset(window->keys, NEPTUNE_RELEASE, NEPTUNE_KEY_LAST + 1);

  window->mouse = (NeptuneButtonState *)malloc((NEPTUNE_MOUSE_LAST + 1) * sizeof(NeptuneButtonState));
  memset(window->mouse, NEPTUNE_RELEASE, NEPTUNE_MOUSE_LAST + 1);

  memset(&window->callbacks, 0, sizeof(window->callbacks));

  platformCreateWindow(window);

  insertWindowIntoGlobalList(window);

  return window;
}

NEPTUNEAPI void neptuneDestroyWindow(NeptuneWindow *window)
{

  assert(window != NULL);

  _NEPTUNE_REQUIRE_INIT();

  platformDestroyWindow(window);
}

NEPTUNEAPI void neptuneDestroyAllWindows()
{

  _NEPTUNE_REQUIRE_INIT();

  if (_neptune.windowListHead == NULL)
    return;

  while (_neptune.windowListHead != NULL)
  {
    NeptuneWindow *pointer = _neptune.windowListHead->next;
    neptuneDestroyWindow(_neptune.windowListHead);
    free(_neptune.windowListHead);
    _neptune.windowListHead = pointer;
  }
}

NEPTUNEAPI NeptuneBool neptuneWindowShouldClose(NeptuneWindow *window)
{

  assert(window != NULL);

  _NEPTUNE_REQUIRE_INIT_OR_RETURN(NEPTUNE_FALSE);

  if (window->shouldClose)
    return window->shouldClose;
  else
    return NEPTUNE_FALSE;
}

NEPTUNEAPI void neptuneSetWindowWrapperPtr(NeptuneWindow *window, void *ptr)
{
  assert(window != NULL);
  _NEPTUNE_REQUIRE_INIT();

  window->wrapperPtr = ptr;
}

NEPTUNEAPI void *neptuneGetWindowWrapperPtr(NeptuneWindow *window)
{
  assert(window != NULL);
  _NEPTUNE_REQUIRE_INIT_OR_RETURN(NULL);

  return window->wrapperPtr;
}

// ---------------------------------------------------
// ---------------------------------------------------
// ----------      NEPTUNE GETTER API       ----------
// ---------------------------------------------------
// ---------------------------------------------------

NEPTUNEAPI void neptuneGetWindowSize(NeptuneWindow *window, int *width, int *height)
{
  assert(window != NULL);

  _NEPTUNE_REQUIRE_INIT();

  platformGetWindowSize(window, width, height);
}
