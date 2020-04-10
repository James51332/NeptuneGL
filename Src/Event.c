#include "Internal.h"

// ---------------------------------------------------
// ---------------------------------------------------
// ----------      NEPTUNE UTILITY API      ----------
// ---------------------------------------------------
// ---------------------------------------------------

void _neptuneRequestError(NeptuneError error, const char *msg)
{
  _NEPTUNE_REQUIRE_INIT();

  if (_neptune.callbacks.error)
  {
    _neptune.callbacks.error(error, msg);
    return;
  }

  switch (error)
  {
  case NEPTUNE_INIT_ERROR:
    printf("NeptuneGL Initialization Error: %s", msg);
    break;
  case NEPTUNE_PLATFORM_ERROR:
    printf("NeptuneGL Platform Error: %s", msg);
    break;
  }
}

void _neptuneRequestRefresh(NeptuneWindow *window)
{
  assert(window != NULL);
  _NEPTUNE_REQUIRE_INIT();

  if (window->callbacks.refresh)
    window->callbacks.refresh(window);
}

void _neptuneRequestClose(NeptuneWindow *window)
{
  assert(window != NULL);
  _NEPTUNE_REQUIRE_INIT();

  window->shouldClose = NEPTUNE_TRUE;

  if (window->callbacks.close)
    window->callbacks.close(window);
}

// ---------------------------------------------------
// ---------------------------------------------------
// ----------      NEPTUNE PUBLIC API       ----------
// ---------------------------------------------------
// ---------------------------------------------------

NEPTUNEAPI void neptunePollEvents(void)
{
  _NEPTUNE_REQUIRE_INIT();

  platformPollEvents();
}

NEPTUNEAPI void neptuneSetKeyCallback(NeptuneWindow *window, NeptuneKeyCallback callback)
{
  _NEPTUNE_REQUIRE_INIT();
  _NEPTUNE_SWAP_POINTERS(window->callbacks.key, callback);
}

NEPTUNEAPI void neptuneSetRefreshCallback(NeptuneWindow *window, NeptuneRefreshCallback callback)
{
  _NEPTUNE_REQUIRE_INIT();
  _NEPTUNE_SWAP_POINTERS(window->callbacks.refresh, callback);
}

NEPTUNEAPI void neptuneSetCloseCallback(NeptuneWindow *window, NeptuneCloseCallback callback)
{
  _NEPTUNE_REQUIRE_INIT();
  _NEPTUNE_SWAP_POINTERS(window->callbacks.close, callback);
}
