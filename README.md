# NeptuneGL
It's Basically GLFW but I'm gonna add Metal and DirectX

## Features
* GLFW Style Window Creation (macOS Only)
* OpenGL 1.1 Ready

## Future
* Desktop Platform Window Creation
* Cross-API Rendering (No Translation)
* Mobile Windowing??

## Compiling The Library
Neptune uses GNU Make for compiling the library. It currently only runs on macOS, so that is all it can compile from. To compile, use `cd` to navigate to the directory and run `make` in the terminal. The Neptune library will appear in the bin folder. If you want to compile the examples, run `make example EXAMPLE=project`, project being the name of the example file.
