#ifdef NEPTUNE_COCOA

#include "Internal.h"

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

- (void)drawRect:(NSRect)dirtyRect {

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

//Platform specific method for obtaining properties of a women
NSUInteger getStyleMask(NeptuneWindow* window) {

  //Set the default values
  NSUInteger styleMask = NSWindowStyleMaskMiniaturizable | NSWindowStyleMaskClosable;

  //Resizable property
  if (window->resizable)
    styleMask |= NSWindowStyleMaskResizable;

  //Check if a title is defined
  if (window->title)
    styleMask |= NSWindowStyleMaskTitled;

  return styleMask;
}

//Neptune's native function for creating a window
void platformCreateWindow(NeptuneWindow* window) {

  //Create the frame for the window (We'll position it later)
  NSRect frame = NSMakeRect(0.0, 0.0, window->width, window->height);

  //Create the window variable
  window->ns.object = [[NeptuneCocoaWindow alloc] initWithContentRect: frame
                                                  styleMask: getStyleMask(window)
                                                    backing: NSBackingStoreBuffered
                                                      defer: NO];

  //Create a delegate (detects close requests)
  window->ns.delegate = [[NeptuneWindowDelegate alloc] init: window];
  [window->ns.object setDelegate: window->ns.delegate];

  //Center the window on the screen (need to cast id type to NSWindow because there is more than one center method)
  [(NeptuneCocoaWindow*)window->ns.object center];

  //Set a title if one is defined
  if (window->title)
    [window->ns.object setTitle:[NSString stringWithUTF8String: window->title]];

  window->ns.view = [[NeptuneView alloc] init: window];
  [window->ns.object setContentView: window->ns.view];

  platformCreateGLContext(window);

  //Show the window object
  [window->ns.object makeKeyAndOrderFront:nil];
  [window->ns.object orderFrontRegardless];

  //OSX requires us to update the application in order to display the window
  platformPollEvents();
}

void platformDestroyWindow(NeptuneWindow* window) {
  [window->ns.object close];
}

NeptuneBool platformWindowShouldClose(NeptuneWindow* window) {
  return window->shouldClose;
}

void platformSwapBuffers(NeptuneWindow* window) {
  [window->context.object flushBuffer];
}

#endif
