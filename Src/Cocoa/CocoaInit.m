#ifdef NEPTUNE_COCOA

#include "Internal.h"

// ---------------------------------------------------
// ---------------------------------------------------
// ----------     NEPTUNE PLATFORM API      ----------
// ---------------------------------------------------
// ---------------------------------------------------

NeptuneBool platformInit(void) {
  @autoreleasepool {
    //Define an application on macOS
    [NSApplication sharedApplication];

    if (!NSApp)
      return NEPTUNE_FALSE;
    else
      return NEPTUNE_TRUE;
  }
}

void platformTerminate(void) {
  @autoreleasepool {
    [NSApp terminate: nil];
  }
}

#endif
