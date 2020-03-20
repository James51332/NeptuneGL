#include "Internal.h"

// ---------------------------------------------------
// ---------------------------------------------------
// ----------      NEPTUNE PUBLIC API       ----------
// ---------------------------------------------------
// ---------------------------------------------------

NEPTUNEAPI int neptuneInit(void) {
  if (platformInit())
    _neptune.initialized = NEPTUNE_TRUE;

  return _neptune.initialized;
}

NEPTUNEAPI void neptuneTerminate(void) {
  _NEPTUNE_REQUIRE_INIT();

  if (_neptune.windowListHead != NULL)
    neptuneDestroyAllWindows();

  platformTerminate();
}
