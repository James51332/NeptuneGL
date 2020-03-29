#include "Internal.h"

// ---------------------------------------------------
// ---------------------------------------------------
// ----------      NEPTUNE UTILITY API      ----------
// ---------------------------------------------------
// ---------------------------------------------------

void _neptuneRequestKey(int key, NeptuneBool state, NeptuneWindow *window) {
  assert(window != NULL);
  _NEPTUNE_REQUIRE_INIT();

  if (key < 0 || key >= 256)
    return;

  window->keys[key] = state;

  if (window->callbacks.key)
    window->callbacks.key(window, key, state);
}

// ---------------------------------------------------
// ---------------------------------------------------
// ----------      NEPTUNE PUBLIC API       ----------
// ---------------------------------------------------
// ---------------------------------------------------

NEPTUNEAPI NeptuneBool neptuneGetKeyStatus(int key, NeptuneWindow* window) {
  assert(window != NULL);

  _NEPTUNE_REQUIRE_INIT_OR_RETURN(NEPTUNE_FALSE);

  if (key < 0 || key >= 256)
    return NEPTUNE_FALSE;

  return window->keys[key];
}
