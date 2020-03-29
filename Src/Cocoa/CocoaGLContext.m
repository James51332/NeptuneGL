#ifdef NEPTUNE_COCOA

#include "Internal.h"

// ---------------------------------------------------
// ---------------------------------------------------
// ----------      NEPTUNE METHOD API       ----------
// ---------------------------------------------------
// ---------------------------------------------------

void platformCreateGLPixelFormat(NeptuneWindow* window) {
  assert(window != NULL);
  _NEPTUNE_REQUIRE_INIT();

  //Credit to
  //https://developer.apple.com/documentation/appkit/nsopenglpixelformat/1436219-initwithattributes?language=objc
  //for this simple opengl pixelformat

  NSOpenGLPixelFormatAttribute attrs[] =
  {
      NSOpenGLPFADoubleBuffer,
      NSOpenGLPFADepthSize, 32,
      NSOpenGLPFAOpenGLProfile, NSOpenGLProfileVersion4_1Core,
      0
  };

  NSOpenGLPixelFormat* pixFmt = [[NSOpenGLPixelFormat alloc] initWithAttributes:attrs];

  window->context.pixelFormat = pixFmt;
}

// ---------------------------------------------------
// ---------------------------------------------------
// ----------     NEPTUNE PLATFORM API      ----------
// ---------------------------------------------------
// ---------------------------------------------------

void platformMakeContextCurrent(NeptuneWindow* window) {
  if (window != NULL)
    [window->context.object makeCurrentContext];
  else
    [NSOpenGLContext clearCurrentContext];
}

void platformSwapBuffers(NeptuneWindow* window) {
  [window->context.object flushBuffer];
}


void platformCreateGLContext(NeptuneWindow* window) {
  assert(window != NULL);
  _NEPTUNE_REQUIRE_INIT();

  platformCreateGLPixelFormat(window);

  window->context.object = [[NSOpenGLContext alloc] initWithFormat:window->context.pixelFormat
                                      shareContext: nil];

  [window->context.object setView: window->ns.view];
}

#endif
