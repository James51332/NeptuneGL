#ifndef NeptuneGL_h
#define NeptuneGL_h

#ifdef __cplusplus
extern "C"
{
#endif

#define NEPTUNE_TRUE 1
#define NEPTUNE_FALSE 0

#ifdef NEPTUNE_COCOA
#include <OpenGL/gl.h>
#endif

  typedef int NeptuneBool;
  typedef int NeptuneKeyState;
  typedef int NeptuneButtonState;

  typedef struct _NeptuneWindow NeptuneWindow;

  typedef enum _NeptuneError
  {
    NEPTUNE_INIT_ERROR,
    NEPTUNE_PLATFORM_ERROR,
  } NeptuneError;

  typedef enum _NeptuneWindowHint
  {
    NEPTUNE_OPENGL_VERSION_MAJOR,
    NEPTUNE_OPENGL_VERSION_MINOR
  } NeptuneWindowHint;

  typedef void (*NeptuneRefreshCallback)(NeptuneWindow *window);
  typedef void (*NeptuneKeyCallback)(NeptuneWindow *window, int key, NeptuneKeyState state);
  typedef void (*NeptuneMouseButtonCallback)(NeptuneWindow *window, int button, NeptuneButtonState state);
  typedef void (*NeptuneCloseCallback)(NeptuneWindow *window);
  typedef void (*NeptuneResizeCallback)(NeptuneWindow *window, int width, int height);
  typedef void (*NeptuneErrorCallback)(NeptuneError error, const char *msg);

#define NEPTUNE_PRESS 1
#define NEPTUNE_RELEASE 0
#define NEPTUNE_REPEAT 2

#define NEPTUNE_MOUSE_LEFT 1
#define NEPTUNE_MOUSE_RIGHT 2

#define NEPTUNE_MOUSE_LAST NEPTUNE_MOUSE_RIGHT

#define NEPTUNE_KEY_UNKNOWN -1

#define NEPTUNE_KEY_TAB 3
#define NEPTUNE_KEY_LEFT_SHIFT 5
#define NEPTUNE_KEY_RIGHT_SHIFT 6
#define NEPTUNE_KEY_FUNCTION 7
#define NEPTUNE_KEY_CONTROL 8
#define NEPTUNE_KEY_LEFT_ALT 9
#define NEPTUNE_KEY_LEFT_OPTION NEPTUNE_KEY_LEFT_ALT 10
#define NEPTUNE_KEY_RIGHT_ALT 11
#define NEPTUNE_KEY_RIGHT_OPTION NEPTUNE_KEY_RIGHT_ALT 12
#define NEPTUNE_KEY_LEFT_COMMAND 13
#define NEPTUNE_KEY_RIGHT_COMMAND 14
#define NEPTUNE_KEY_UP 15
#define NEPTUNE_KEY_RIGHT 16
#define NEPTUNE_KEY_DOWN 17
#define NEPTUNE_KEY_LEFT 18

#define NEPTUNE_KEY_ESCAPE 33
#define NEPTUNE_KEY_SPACE 40
#define NEPTUNE_KEY_MINUS 43
#define NEPTUNE_KEY_COMMA 44
#define NEPTUNE_KEY_PERIOD 46
#define NEPTUNE_KEY_SLASH 47

#define NEPTUNE_KEY_0 48
#define NEPTUNE_KEY_1 49
#define NEPTUNE_KEY_2 50
#define NEPTUNE_KEY_3 51
#define NEPTUNE_KEY_4 52
#define NEPTUNE_KEY_5 53
#define NEPTUNE_KEY_6 54
#define NEPTUNE_KEY_7 55
#define NEPTUNE_KEY_8 56
#define NEPTUNE_KEY_9 57

#define NEPTUNE_KEY_SEMICOLON 59
#define NEPTUNE_KEY_LESS_THAN 60
#define NEPTUNE_KEY_EQUALS 61
#define NEPTUNE_KEY_GREATER_THAN 62

#define NEPTUNE_KEY_A 65
#define NEPTUNE_KEY_B 66
#define NEPTUNE_KEY_C 67
#define NEPTUNE_KEY_D 68
#define NEPTUNE_KEY_E 69
#define NEPTUNE_KEY_F 70
#define NEPTUNE_KEY_G 71
#define NEPTUNE_KEY_H 72
#define NEPTUNE_KEY_I 73
#define NEPTUNE_KEY_J 74
#define NEPTUNE_KEY_K 75
#define NEPTUNE_KEY_L 76
#define NEPTUNE_KEY_M 77
#define NEPTUNE_KEY_N 78
#define NEPTUNE_KEY_O 79
#define NEPTUNE_KEY_P 80
#define NEPTUNE_KEY_Q 81
#define NEPTUNE_KEY_R 82
#define NEPTUNE_KEY_S 83
#define NEPTUNE_KEY_T 84
#define NEPTUNE_KEY_U 85
#define NEPTUNE_KEY_V 86
#define NEPTUNE_KEY_W 87
#define NEPTUNE_KEY_X 88
#define NEPTUNE_KEY_Y 89
#define NEPTUNE_KEY_Z 90

#define NEPTUNE_KEY_LEFT_BRACKET 91
#define NEPTUNE_KEY_BACKSLASH 92
#define NEPTUNE_KEY_RIGHT_BRACKET 93
#define NEPTUNE_KEY_BACKSPACE 127

#define NEPTUNE_KEY_LAST NEPTUNE_KEY_BACKSPACE

  // ---------------------------------------------------
  // ---------------------------------------------------
  // ----------      NEPTUNE PUBLIC API       ----------
  // ---------------------------------------------------
  // ---------------------------------------------------

  int neptuneInit(void);
  void neptuneTerminate(void);
  void neptunePollEvents(void);
  const char *neptuneGetKeyString(int key);
  void neptuneDestroyAllWindows(void);
  void neptuneSetWindowWrapperPtr(NeptuneWindow *window, void *ptr);
  void *neptuneGetWindowWrapperPtr(NeptuneWindow *window);
  void neptuneSwapBuffers(NeptuneWindow *window);
  void neptuneDestroyWindow(NeptuneWindow *window);
  NeptuneBool neptuneWindowShouldClose(NeptuneWindow *window);
  void neptuneMakeContextCurrent(NeptuneWindow *window);
  void neptuneWindowHint(NeptuneWindowHint type, int val);
  NeptuneBool neptuneGetKeyStatus(int key, NeptuneWindow *window);
  NeptuneWindow *neptuneCreateWindow(int width, int height, const char *title);
  void neptuneSetKeyCallback(NeptuneWindow *window, NeptuneKeyCallback callback);
  void neptuneGetWindowSize(NeptuneWindow *window, int *width, int *height);
  void neptuneSetRefreshCallback(NeptuneWindow *window, NeptuneRefreshCallback callback);
  void neptuneSetCloseCallback(NeptuneWindow *window, NeptuneCloseCallback callback);

#ifdef __cplusplus
}
#endif

#endif /* end of include guard: NeptuneGL_h */
