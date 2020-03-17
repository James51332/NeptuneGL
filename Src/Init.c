#include "Internal.h"

NEPTUNEAPI void neptuneInit() {
  if (platformInit())
    _neptune.initialized = NEPTUNE_TRUE;
}

NEPTUNEAPI void neptunePollEvents() {
  platformPollEvents();
}

NEPTUNEAPI void neptuneTerminate() {
  platformTerminate();
}
