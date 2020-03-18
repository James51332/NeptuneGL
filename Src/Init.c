#include "Internal.h"

NEPTUNEAPI int neptuneInit() {
  if (platformInit())
    _neptune.initialized = NEPTUNE_TRUE;

  return _neptune.initialized;
}

NEPTUNEAPI void neptunePollEvents() {
  _NEPTUNE_REQUIRE_INIT;

  platformPollEvents();
}

NEPTUNEAPI void neptuneTerminate() {
  _NEPTUNE_REQUIRE_INIT;

  platformTerminate();
}
