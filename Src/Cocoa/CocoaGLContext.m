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

  NSOpenGLPixelFormat* pixFmt;

  if (_neptune.hints.glmajor == 4 && _neptune.hints.glminor == 1) {

    NSOpenGLPixelFormatAttribute attrs[] = {
      NSOpenGLPFADoubleBuffer,
      NSOpenGLPFADepthSize, 32,
      NSOpenGLPFAOpenGLProfile, NSOpenGLProfileVersion4_1Core,
      0
    };

    pixFmt = [[NSOpenGLPixelFormat alloc] initWithAttributes:attrs];
  } else if (_neptune.hints.glmajor == 3 && _neptune.hints.glminor == 2) {

    NSOpenGLPixelFormatAttribute attrs[] = {
      NSOpenGLPFADoubleBuffer,
      NSOpenGLPFADepthSize, 32,
      NSOpenGLPFAOpenGLProfile, NSOpenGLProfileVersion3_2Core,
      0
    };

    pixFmt = [[NSOpenGLPixelFormat alloc] initWithAttributes:attrs];
  } else {

    NSOpenGLPixelFormatAttribute attrs[] = {
      NSOpenGLPFADoubleBuffer,
      NSOpenGLPFADepthSize, 32,
      0
    };

    pixFmt = [[NSOpenGLPixelFormat alloc] initWithAttributes:attrs];
  }

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
