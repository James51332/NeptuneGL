#ifdef NEPTUNE_COCOA

#include "Internal.h"

// ---------------------------------------------------
// ---------------------------------------------------
// ----------     NEPTUNE PLATFORM API      ----------
// ---------------------------------------------------
// ---------------------------------------------------

void platformPollEvents(void) {
  //Loop if there is more than one event
  for (;;) {
    NSEvent* event = [NSApp nextEventMatchingMask: NSEventMaskAny
                                        untilDate: [NSDate distantPast]
                                           inMode: NSDefaultRunLoopMode
                                          dequeue: YES];

    //If there is are no more events, return
    if (!event)
      return;
    else
      [NSApp sendEvent: event];
  }
}

#endif
