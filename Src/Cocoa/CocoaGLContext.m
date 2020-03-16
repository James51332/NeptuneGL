#ifdef NEPTUNE_COCOA

#include "Internal.h"

void platformCreateGLContext(NeptuneWindow* window) {
  assert(window != NULL);
  _NEPTUNE_REQUIRE_INIT;

  platformCreateGLPixelFormat(window);

  window->context.object = [[NSOpenGLContext alloc] initWithFormat:window->context.pixelFormat
                                      shareContext: nil];

  [window->context.object setView: window->ns.view];
}

void platformCreateGLPixelFormat(NeptuneWindow* window) {
  assert(window != NULL);
  _NEPTUNE_REQUIRE_INIT;

  //Thanks to https://developer.apple.com/documentation/appkit/nsopenglpixelformat/1436219-initwithattributes?language=objc
  //for this simple opengl pixelformat
  NSOpenGLPixelFormatAttribute attrs[] =
  {
      NSOpenGLPFADoubleBuffer,
      NSOpenGLPFADepthSize, 32,
      0
  };

  NSOpenGLPixelFormat* pixFmt = [[NSOpenGLPixelFormat alloc] initWithAttributes:attrs];

  if(pixFmt == nil) {

  }

  window->context.pixelFormat = pixFmt;

}

void platformMakeContextCurrent(NeptuneWindow* window) {
  [window->context.object makeCurrentContext];
}

#endif
