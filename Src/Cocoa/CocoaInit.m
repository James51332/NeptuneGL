#ifdef NEPTUNE_COCOA

#include "Internal.h"

@interface NeptuneDelegate : NSObject <NSApplicationDelegate>
@end

@implementation NeptuneDelegate
//Fix (macOS apps are weird and don't close with the window)
- (BOOL) applicationShouldTerminateAfterLastWindowClosed:(NSNotification *)sender {
  return YES;
}
@end

NeptuneBool platformInit() {
  //Define an application on macOS
  [NSApplication sharedApplication];

  if (!NSApp)
    return NEPTUNE_FALSE;
  else
    return NEPTUNE_TRUE;
}

void platformPollEvents() {
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

void platformTerminate() {
  [NSApp terminate: nil];
}

#endif
