#ifndef Neptune_h
#define Neptune_h

#define NEPTUNE_TRUE 1
#define NEPTUNE_FALSE 0

typedef int NeptuneBool;

typedef struct NeptuneWindow NeptuneWindow;

void neptuneInit(void);
NeptuneWindow* neptuneCreateWindow(int width, int height, const char* title);
void neptunePollEvents(void);
void neptuneDestroyWindow(NeptuneWindow* window);
NeptuneBool neptuneShouldWindowClose(NeptuneWindow* window);
void neptuneTerminate(void);

#endif /* end of include guard: Neptune_h */
