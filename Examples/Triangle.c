#include <OpenGL/gl.h>
#include <Neptune/Neptune.h>

int main() {
  neptuneInit();

  NeptuneWindow *window = neptuneCreateWindow(800, 600, "Example Triangle");

  neptuneMakeContextCurrent(window);

  while (!neptuneWindowShouldClose(window)) {
    glBegin(GL_TRIANGLES);
    glVertex2d(0.0f, 0.5f);
    glVertex2d(0.5f, -0.5f);
    glVertex2d(-0.5f, -0.5f);
    glEnd();

    neptuneSwapBuffers(window);
    neptunePollEvents();
  }

  neptuneTerminate();
}
