#ifndef CocoaPlatform_h
#define CocoaPlatform_h

#include "CocoaGLContext.h"

//Cocoa native window type
typedef struct NeptuneWindowNS {
  id object;
  id view;
  id delegate;

} NeptuneWindowNS;

//platform window creation macro
#define _NEPTUNE_PLATFORM_WINDOW_CONTEXT NeptuneWindowNS ns
#define _NEPTUNE_PLATFORM_GL_CONTEXT NeptuneContextNS context

#endif /* end of include guard: CocoaPlatform_h */
