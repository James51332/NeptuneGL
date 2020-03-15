#ifndef Internal_h
#define Internal_h

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

//Cocoa ID Translation
#ifdef __OBJC__
  #include <Cocoa/Cocoa.h>
#else
  typedef void* id;
#endif

//Platform Includes
#ifdef NEPTUNE_COCOA
  #include "Cocoa/CocoaPlatform.h"
#endif

//Public Header Prototypes
#include "../Include/Neptune/Neptune.h"

//Global for information about the library
typedef struct _NeptuneLibrary {
  NeptuneBool initialized;

} _NeptuneLibrary;

extern _NeptuneLibrary _neptune;

#define _NEPTUNE_REQUIRE_INIT \
if (!_neptune.initialized) { \
  printf("Initialize Neptune before doing this"); \
  exit(0); \
}

//Private Structs
struct NeptuneWindow {
  int width;
  int height;
  const char* title;

  NeptuneBool resizable;
  NeptuneBool shouldClose;

  //Platform specific window context (defined in platform header file)
  _NEPTUNE_PLATFORM_WINDOW_CONTEXT;
};

//Private Methods
NeptuneBool platformInit(void);
void platformCreateWindow(NeptuneWindow* window);
void platformPollEvents(void);
void platformDestroyWindow(NeptuneWindow* window);
NeptuneBool platformShouldWindowClose(NeptuneWindow* window);
void platformTerminate(void);

#endif /* end of include guard: Internal_h */
