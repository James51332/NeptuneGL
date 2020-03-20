#include "Internal.h"

// ---------------------------------------------------
// ---------------------------------------------------
// ----------      NEPTUNE PUBLIC API       ----------
// ---------------------------------------------------
// ---------------------------------------------------

NEPTUNEAPI void neptuneSwapBuffers(NeptuneWindow* window) {

  assert(window != NULL);

  _NEPTUNE_REQUIRE_INIT();

  platformSwapBuffers(window);
}

NEPTUNEAPI void neptuneMakeContextCurrent(NeptuneWindow* window) {

  assert(window != NULL);

  _NEPTUNE_REQUIRE_INIT();

  platformMakeContextCurrent(window);
}
