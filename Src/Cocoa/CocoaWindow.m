#ifdef NEPTUNE_COCOA

#include "Internal.h"

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

static int translateKey(unsigned short key) {
  if (key < 0 || key >= sizeof(_neptune.ns.keyCode))
    return NEPTUNE_KEY_UNKNOWN;

  return _neptune.ns.keyCode[key];
}

// ---------------------------------------------------
// ---------------------------------------------------
// ----------       NEPTUNE OBJC API        ----------
// ---------------------------------------------------
// ---------------------------------------------------

@interface NeptuneWindowDelegate : NSObject <NSWindowDelegate> {
  NeptuneWindow* window;
}
- (id) init:(NeptuneWindow*)handle;
@end

@implementation NeptuneWindowDelegate
- (id) init:(NeptuneWindow*)handle {
  window = handle;
  return self;
}

- (BOOL) windowShouldClose:(NSWindow*)win {
  _neptuneRequestClose(window);

  return NO;
}

@end

@interface NeptuneView : NSView {
  NeptuneWindow* window;
  NSTimer *timer;
}
- (id) init:(NeptuneWindow*)win;
@end

@implementation NeptuneView
- (id) init:(NeptuneWindow*)win {
  if (self) {
    window = win;
  }

  timer = [NSTimer scheduledTimerWithTimeInterval:0.05f target:self selector:@selector(redraw) userInfo:nil repeats:YES];

  return self;
}

- (void) redraw {
  [self setNeedsDisplay:YES];
}

- (BOOL) acceptsFirstResponder {
  return YES;
}

- (BOOL) canBecomeKeyView {
  return YES;
}

- (void)mouseDown:(NSEvent *)event {
  _neptuneRequestMouseButton(window, NEPTUNE_MOUSE_LEFT, NEPTUNE_PRESS);
}

- (void)mouseUp:(NSEvent *)event {
  _neptuneRequestMouseButton(window, NEPTUNE_MOUSE_LEFT, NEPTUNE_RELEASE);
}

- (void)mouseMoved:(NSEvent *)event {
  
}

- (void)mouseDragged:(NSEvent *)event {
  [self mouseMoved:event];
}

- (void)keyDown:(NSEvent *)event {
  _neptuneRequestKey(translateKey([event keyCode]), NEPTUNE_PRESS, window);
}

- (void)keyUp:(NSEvent *)event {
  _neptuneRequestKey(translateKey([event keyCode]), NEPTUNE_RELEASE, window);
}

- (void)drawRect:(NSRect)dirtyRect {
  _neptuneRequestRefresh(window);
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
// ----------     NEPTUNE PLATFORM API      ----------
// ---------------------------------------------------
// ---------------------------------------------------

void platformCreateWindow(NeptuneWindow* window) {
    NSRect frame = NSMakeRect(0.0, 0.0, window->initwidth, window->initheight);
    window->initwidth = 0;
    window->initheight = 0;

    window->ns.object = [[NeptuneCocoaWindow alloc] initWithContentRect: frame
                                                              styleMask: getStyleMask(window)
                                                                backing: NSBackingStoreBuffered
                                                                  defer: NO];

    window->ns.delegate = [[NeptuneWindowDelegate alloc] init: window];

    [(NeptuneCocoaWindow *)window->ns.object center];

    if (window->title)
      [window->ns.object setTitle: [NSString stringWithUTF8String: window->title]];

    window->ns.view = [[NeptuneView alloc] init: window];
    [window->ns.object setContentView: window->ns.view];
    [window->ns.object makeFirstResponder: window->ns.view];
    [window->ns.object setDelegate: window->ns.delegate];
    [window->ns.object setAcceptsMouseMovedEvents:YES];
    [window->ns.object makeKeyAndOrderFront:nil];
    [window->ns.object orderFrontRegardless];

    platformCreateGLContext(window);

    //macOS requires us to update the application in order to display the window
    neptunePollEvents();
}

void platformDestroyWindow(NeptuneWindow* window) {
  [window->ns.object setContentView:nil];
  [window->ns.view release];
  window->ns.view = nil;

  [window->ns.object setDelegate:nil];
  [window->ns.delegate release];
  window->ns.delegate = nil;

  [window->ns.object close];
  [window->ns.object release];
  window->ns.object = nil;
}

void platformGetWindowSize(NeptuneWindow *window, int *width, int *height) {
  @autoreleasepool {

  NSRect frame = [window->ns.view frame];

  if (width)
    *width = frame.size.width;

  if (height)
    *height = frame.size.height;

  }
}

#endif
