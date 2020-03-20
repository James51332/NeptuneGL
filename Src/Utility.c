#include "Internal.h"

// ---------------------------------------------------
// ---------------------------------------------------
// ----------      NEPTUNE UTILITY API      ----------
// ---------------------------------------------------
// ---------------------------------------------------

void _neptuneRequestError(NeptuneError error, const char* msg) {
  switch (error) {
    case _NEPTUNE_INIT_ERROR:
      printf("NeptuneGL Initialization Error: %s", msg);
    case _NEPTUNE_PLATFORM_ERROR:
      printf("NeptuneGL Platform Error: %s", msg);
  }
}
