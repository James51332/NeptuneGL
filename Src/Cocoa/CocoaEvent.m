#ifdef NEPTUNE_COCOA

#include "Internal.h"

// ---------------------------------------------------
// ---------------------------------------------------
// ----------     NEPTUNE PLATFORM API      ----------
// ---------------------------------------------------
// ---------------------------------------------------

void platformPollEvents(void) {
  @autoreleasepool {
    //Loop if there is more than one event
    for (;;) {
      NSEvent* event = [NSApp nextEventMatchingMask:NSEventMaskAny
                                          untilDate:[NSDate distantPast]
                                             inMode:NSDefaultRunLoopMode
                                            dequeue:YES];

      //If there is are no more events, return
      if (!event)
        break;
      else
        [NSApp sendEvent: event];
    }
  }
}

#endif
