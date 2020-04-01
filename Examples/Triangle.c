#include <OpenGL/gl.h>
#include <Neptune/Neptune.h>
#include <stdio.h>

int main() {
  neptuneInit();

  NeptuneWindow *window = neptuneCreateWindow(800, 600, "Example Triangle");
  neptuneWindowHint(NEPTUNE_OPENGL_VERSION_MAJOR, 4);
  neptuneWindowHint(NEPTUNE_OPENGL_VERSION_MINOR, 1);

  neptuneMakeContextCurrent(window);

  while (!neptuneWindowShouldClose(window)) {
    glBegin(GL_TRIANGLES);
    glVertex2d(0.0f, 0.5f);
    glVertex2d(0.5f, -0.5f);
    glVertex2d(-0.5f, -0.5f);
    glEnd();

    //TODO: Implement Triangle With OpenGL 4.1

    fflush(stdout);

    neptuneSwapBuffers(window);
    neptunePollEvents();
  }

  neptuneTerminate();
}
