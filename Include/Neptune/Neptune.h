#ifndef Neptune_h
#define Neptune_h

#define NEPTUNE_TRUE 1
#define NEPTUNE_FALSE 0

typedef int NeptuneBool;

#ifdef NEPTUNE_COCOA
  #include <OpenGL/gl.h>
#endif

typedef struct _NeptuneWindow NeptuneWindow;

int neptuneInit(void);
NeptuneWindow* neptuneCreateWindow(int width, int height, const char* title);
void neptunePollEvents(void);
void neptuneDestroyWindow(NeptuneWindow* window);
NeptuneBool neptuneWindowShouldClose(NeptuneWindow* window);
void neptuneMakeContextCurrent(NeptuneWindow* window);
void neptuneTerminate(void);
void neptuneSwapBuffers(NeptuneWindow* window);

#endif /* end of include guard: Neptune_h */
