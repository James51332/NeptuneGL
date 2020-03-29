#include "Internal.h"

// ---------------------------------------------------
// ---------------------------------------------------
// ----------      NEPTUNE METHOD API       ----------
// ---------------------------------------------------
// ---------------------------------------------------

void defaultWindowHints(void) {
  _neptune.version.major = 1;
  _neptune.version.minor = 0;
}

// ---------------------------------------------------
// ---------------------------------------------------
// ----------      NEPTUNE PUBLIC API       ----------
// ---------------------------------------------------
// ---------------------------------------------------

NEPTUNEAPI int neptuneInit(void) {
  if (platformInit())
    _neptune.initialized = NEPTUNE_TRUE;

  defaultInitHints();

  return _neptune.initialized;
}

NEPTUNEAPI void neptuneTerminate(void) {
  _NEPTUNE_REQUIRE_INIT();

  if (_neptune.windowListHead != NULL)
    neptuneDestroyAllWindows();

  platformTerminate();
}
