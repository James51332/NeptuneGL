#include <Neptune/Neptune.h>

int main() {
  neptuneInit();

  NeptuneWindow* window1 = neptuneCreateWindow(800, 600, "Window 1");
  NeptuneWindow* window2 = neptuneCreateWindow(800, 600, "Window 2");

  while (!neptuneWindowShouldClose(window1) || !neptuneWindowShouldClose(window2)) {
    if (neptuneWindowShouldClose(window1))
      neptuneDestroyWindow(window1);

    if (neptuneWindowShouldClose(window2))
      neptuneDestroyWindow(window2);

    neptunePollEvents();
  }

  neptuneTerminate();
}
