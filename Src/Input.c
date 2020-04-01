#include "Internal.h"

// ---------------------------------------------------
// ---------------------------------------------------
// ----------      NEPTUNE UTILITY API      ----------
// ---------------------------------------------------
// ---------------------------------------------------

void _neptuneRequestKey(int key, NeptuneKeyState state, NeptuneWindow *window) {
  assert(window != NULL);
  _NEPTUNE_REQUIRE_INIT();

  if (key < 0 || key >= 256)
    return;

  if (state == NEPTUNE_RELEASE)
    window->keys[key] = state;

  if (window->keys[key] == NEPTUNE_RELEASE)
    window->keys[key] = state;
  else
    window->keys[key] = NEPTUNE_REPEAT;


  if (window->callbacks.key)
    window->callbacks.key(window, key, window->keys[key]);
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

NEPTUNEAPI const char* neptuneGetKeyString(int key) {
  return _neptune.keyStrings[key];
}
