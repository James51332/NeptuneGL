#include "Internal.h"

void neptuneInit() {
  if (platformInit())
    _neptune.initialized = NEPTUNE_TRUE;
}

void neptunePollEvents() {
  platformPollEvents();
}

void neptuneTerminate() {
  platformTerminate();
}
