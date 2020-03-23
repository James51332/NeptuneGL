#include <Neptune/Neptune.h>

int main() {
  neptuneInit();

  NeptuneWindow* window = neptuneCreateWindow(1080, 720, "Example Window");
  
  while (!neptuneWindowShouldClose(window))
    neptunePollEvents();

  neptuneTerminate();
}
