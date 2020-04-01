#ifndef CocoaPlatform_h
#define CocoaPlatform_h

#include "CocoaGLContext.h"

//Cocoa native window type
typedef struct _NeptuneWindowNS {
  id object;
  id view;
  id delegate;

} NeptuneWindowNS;

typedef struct _NeptuneGlobalNS {
  short int keyCode[256];
  id menu;
} NeptuneGlobalNS;

//platform window creation macro
#define _NEPTUNE_PLATFORM_WINDOW_CONTEXT NeptuneWindowNS ns
#define _NEPTUNE_PLATFORM_GL_CONTEXT NeptuneContextNS context
#define _NEPTUNE_GLOBAL_PLATFORM_CONTEXT NeptuneGlobalNS ns

#endif /* end of include guard: CocoaPlatform_h */
