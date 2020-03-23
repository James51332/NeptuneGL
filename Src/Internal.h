#ifndef Internal_h
#define Internal_h

//Standard C Includes
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Cocoa ID Translation
#ifdef __OBJC__
  #include <Cocoa/Cocoa.h>
#else
  typedef void* id;
#endif

//Platform Includes
#ifdef NEPTUNE_COCOA

#ifdef NEPTUNE_DYNAMIC
  #define NEPTUNEAPI __attribute__((visibility("default")))
#else
  #define NEPTUNEAPI
#endif

#include "Cocoa/CocoaPlatform.h"

#else

#define NEPTUNEAPI

#endif

//Public Header Prototypes
#include "../Include/Neptune/Neptune.h"

//Global for information about the library
typedef struct _NeptuneLibrary {
  NeptuneBool initialized;

  NeptuneWindow* windowListHead;

  _NEPTUNE_GLOBAL_PLATFORM_CONTEXT;

} _NeptuneLibrary;

extern _NeptuneLibrary _neptune;

//Private Structs
struct _NeptuneWindow {
  struct _NeptuneWindow* next;

  int width;
  int height;
  const char* title;

  NeptuneBool resizable;
  NeptuneBool shouldClose;

  //Platform specific window context (defined in platform header file)
  _NEPTUNE_PLATFORM_WINDOW_CONTEXT;

  //Platform specific OpenGL context
  _NEPTUNE_PLATFORM_GL_CONTEXT;
};

//Private Enums
typedef enum _NeptuneError {
  _NEPTUNE_INIT_ERROR,
  _NEPTUNE_PLATFORM_ERROR,
} NeptuneError;

// ---------------------------------------------------
// ---------------------------------------------------
// ----------     NEPTUNE PLATFORM API      ----------
// ---------------------------------------------------
// ---------------------------------------------------
NeptuneBool                                             platformInit(void);
void                                               platformTerminate(void);
void                           platformCreateWindow(NeptuneWindow* window);
void                          platformDestroyWindow(NeptuneWindow* window);
void                    platformCreateGLPixelFormat(NeptuneWindow* window);
void                        platformCreateGLContext(NeptuneWindow* window);
void                     platformMakeContextCurrent(NeptuneWindow* window);
void                            platformSwapBuffers(NeptuneWindow* window);
void                                              platformPollEvents(void);

// ---------------------------------------------------
// ---------------------------------------------------
// ----------     NEPTUNE UTILITY API       ----------
// ---------------------------------------------------
// ---------------------------------------------------
void             _neptuneRequestError(NeptuneError error, const char* msg);


#define _NEPTUNE_REQUIRE_INIT() \
if (!_neptune.initialized) { \
  _neptuneRequestError(_NEPTUNE_INIT_ERROR, "Please Initialize Neptune"); \
  return; \
}

#define _NEPTUNE_REQUIRE_INIT_OR_RETURN(x) \
if (!_neptune.initialized) { \
  _neptuneRequestError(_NEPTUNE_INIT_ERROR, "Please Initialize Neptune"); \
  return x; \
}

#endif /* end of include guard: Internal_h */
