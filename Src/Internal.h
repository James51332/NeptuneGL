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
typedef void *id;
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
typedef struct _NeptuneLibrary
{
  NeptuneBool initialized;

  NeptuneWindow *windowListHead;

  struct
  {
    NeptuneErrorCallback error;
  } callbacks;

  _NEPTUNE_GLOBAL_PLATFORM_CONTEXT;

  struct
  {
    int glmajor;
    int glminor;
  } hints;

  const char *keyStrings[NEPTUNE_KEY_LAST + 1];

} _NeptuneLibrary;

extern _NeptuneLibrary _neptune;

//Private Structs
struct _NeptuneWindow
{
  struct _NeptuneWindow *next;

  void *wrapperPtr;

  int initwidth;
  int initheight;
  const char *title;

  NeptuneBool resizable;
  NeptuneBool shouldClose;

  NeptuneKeyState *keys;

  NeptuneButtonState *mouse;

  struct
  {
    NeptuneRefreshCallback refresh;
    NeptuneKeyCallback key;
    NeptuneCloseCallback close;
    NeptuneMouseButtonCallback mouseButton;
  } callbacks;

  //Platform specific window/gl context (defined in platform header file)
  _NEPTUNE_PLATFORM_WINDOW_CONTEXT;
  _NEPTUNE_PLATFORM_GL_CONTEXT;
};

// ---------------------------------------------------
// ---------------------------------------------------
// ----------     NEPTUNE PLATFORM API      ----------
// ---------------------------------------------------
// ---------------------------------------------------

NeptuneBool platformInit(void);
void _neptuneInitGL(void);
void platformTerminate(void);
void platformGetWindowSize(NeptuneWindow *window, int *width, int *height);
void platformCreateWindow(NeptuneWindow *window);
void platformDestroyWindow(NeptuneWindow *window);
void platformCreateGLPixelFormat(NeptuneWindow *window);
void platformCreateGLContext(NeptuneWindow *window);
void platformMakeContextCurrent(NeptuneWindow *window);
void platformSwapBuffers(NeptuneWindow *window);
void platformPollEvents(void);

// ---------------------------------------------------
// ---------------------------------------------------
// ----------     NEPTUNE UTILITY API       ----------
// ---------------------------------------------------
// ---------------------------------------------------

void _neptuneRequestError(NeptuneError error, const char *msg);
void _neptuneRequestKey(int key, NeptuneKeyState down, NeptuneWindow *window);
void _neptuneRequestRefresh(NeptuneWindow *window);
void _neptuneRequestClose(NeptuneWindow *window);
void _neptuneRequestResize(NeptuneWindow *window, int width, int height);
void _neptuneRequestMouseButton(NeptuneWindow *window, int button, NeptuneButtonState state);

#define _NEPTUNE_SWAP_POINTERS(x, y) \
  {                                  \
    void *a;                         \
    a = x;                           \
    x = y;                           \
    y = a;                           \
  }

#define _NEPTUNE_REQUIRE_INIT()                                            \
  if (!_neptune.initialized)                                               \
  {                                                                        \
    _neptuneRequestError(NEPTUNE_INIT_ERROR, "Please Initialize Neptune"); \
    return;                                                                \
  }

#define _NEPTUNE_REQUIRE_INIT_OR_RETURN(x)                                 \
  if (!_neptune.initialized)                                               \
  {                                                                        \
    _neptuneRequestError(NEPTUNE_INIT_ERROR, "Please Initialize Neptune"); \
    return x;                                                              \
  }

#endif /* end of include guard: Internal_h */
