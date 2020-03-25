#include "Internal.h"

// ---------------------------------------------------
// ---------------------------------------------------
// ----------      NEPTUNE UTILITY API      ----------
// ---------------------------------------------------
// ---------------------------------------------------

void _neptuneRequestError(NeptuneError error, const char* msg) {
  _NEPTUNE_REQUIRE_INIT();

  switch (error) {
    case _NEPTUNE_INIT_ERROR:
      printf("NeptuneGL Initialization Error: %s", msg);
    case _NEPTUNE_PLATFORM_ERROR:
      printf("NeptuneGL Platform Error: %s", msg);
  }
}

void _neptuneRequestRefresh(NeptuneWindow *window) {
  if (window->callbacks.refresh)
    window->callbacks.refresh(window);
}

// ---------------------------------------------------
// ---------------------------------------------------
// ----------      NEPTUNE PUBLIC API       ----------
// ---------------------------------------------------
// ---------------------------------------------------

NEPTUNEAPI void neptuneSetKeyCallback(NeptuneWindow *window, NeptuneKeyCallback callback) {
  _NEPTUNE_REQUIRE_INIT();
  _NEPTUNE_SWAP_POINTERS(window->callbacks.key, callback);
}

NEPTUNEAPI void neptuneSetRefreshCallback(NeptuneWindow *window, NeptuneRefreshCallback callback) {
  _NEPTUNE_REQUIRE_INIT();
  _NEPTUNE_SWAP_POINTERS(window->callbacks.refresh, callback);
}
