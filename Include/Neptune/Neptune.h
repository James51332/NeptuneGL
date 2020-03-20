#ifndef Neptune_h
#define Neptune_h

#define NEPTUNE_TRUE 1
#define NEPTUNE_FALSE 0

#ifdef NEPTUNE_COCOA
  #include <OpenGL/gl.h>
#endif

typedef int NeptuneBool;
typedef struct _NeptuneWindow NeptuneWindow;

// ---------------------------------------------------
// ---------------------------------------------------
// ----------      NEPTUNE PUBLIC API       ----------
// ---------------------------------------------------
// ---------------------------------------------------

int neptuneInit(void);
void neptuneTerminate(void);

NeptuneWindow* neptuneCreateWindow(int width, int height, const char* title);
NeptuneBool neptuneWindowShouldClose(NeptuneWindow* window);

void neptuneDestroyWindow(NeptuneWindow* window);
void neptuneDestroyAllWindows(void);

void neptuneMakeContextCurrent(NeptuneWindow* window);
void neptuneSwapBuffers(NeptuneWindow* window);

void neptunePollEvents(void);


void neptuneGetWindowSize(NeptuneWindow* window, int* width, int* height);

#endif /* end of include guard: Neptune_h */
