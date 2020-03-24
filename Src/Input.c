#include "Internal.h"

NeptuneBool neptuneGetKeyStatus(int key, NeptuneWindow* window) {
  _NEPTUNE_REQUIRE_INIT_OR_RETURN(NEPTUNE_FALSE);

  if (key < 0 || key >= 256)
    return NEPTUNE_FALSE;

  return window->keys[key];
}
