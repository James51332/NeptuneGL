#ifdef NEPTUNE_COCOA

#include "Internal.h"

// ---------------------------------------------------
// ---------------------------------------------------
// ----------       NEPTUNE OBJC API        ----------
// ---------------------------------------------------
// ---------------------------------------------------

@interface NeptuneWindowDelegate : NSObject <NSWindowDelegate> {
  NeptuneWindow* ptr;
}
- (id) init:(NeptuneWindow*)window;
@end

@implementation NeptuneWindowDelegate
- (id) init:(NeptuneWindow*)window {
  ptr = window;

  return self;
}

- (BOOL) windowShouldClose:(NSWindow*)window {
  ptr->shouldClose = NEPTUNE_TRUE;
  return NO;
}
@end

@interface NeptuneView : NSView {
  NeptuneWindow* window;
}
- (id) init:(NeptuneWindow*)win;
@end

@implementation NeptuneView
- (id) init:(NeptuneWindow*)win {
  window = win;

  self = [[NeptuneView alloc] initWithFrame: NSMakeRect(0.0, 0.0, window->width, window->height)];

  return self;
}
@end

@interface NeptuneCocoaWindow : NSWindow
@end

@implementation NeptuneCocoaWindow
- (BOOL) canBecomeKeyWindow {
  return YES;
}
- (BOOL) canBecomeMainWindow {
  return YES;
}
@end

// ---------------------------------------------------
// ---------------------------------------------------
// ----------      NEPTUNE METHOD API       ----------
// ---------------------------------------------------
// ---------------------------------------------------

NSUInteger getStyleMask(NeptuneWindow* window) {
  NSUInteger styleMask = NSWindowStyleMaskMiniaturizable | NSWindowStyleMaskClosable;

  if (window->resizable)
    styleMask |= NSWindowStyleMaskResizable;

  if (window->title)
    styleMask |= NSWindowStyleMaskTitled;

  return styleMask;
}

// ---------------------------------------------------
// ---------------------------------------------------
// ----------     NEPTUNE PLATFORM API      ----------
// ---------------------------------------------------
// ---------------------------------------------------

void platformCreateWindow(NeptuneWindow* window) {
  @autoreleasepool {
    NSRect frame = NSMakeRect(0.0, 0.0, window->width, window->height);

    window->ns.object = [[NeptuneCocoaWindow alloc] initWithContentRect: frame
                                                              styleMask: getStyleMask(window)
                                                                backing: NSBackingStoreBuffered
                                                                  defer: NO];

    window->ns.delegate = [[NeptuneWindowDelegate alloc] init: window];
    [window->ns.object setDelegate: window->ns.delegate];

    [(NeptuneCocoaWindow*)window->ns.object center];

    if (window->title)
      [window->ns.object setTitle:[NSString stringWithUTF8String: window->title]];

    window->ns.view = [[NeptuneView alloc] init: window];
    [window->ns.object setContentView: window->ns.view];

    platformCreateGLContext(window);

    [window->ns.object makeKeyAndOrderFront:nil];
    [window->ns.object orderFrontRegardless];

    //OSX requires us to update the application in order to display the window
    neptunePollEvents();
  }
}

void platformDestroyWindow(NeptuneWindow* window) {
  [window->ns.object close];
}

#endif
