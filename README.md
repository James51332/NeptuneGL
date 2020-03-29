# NeptuneGL
It's Basically GLFW but I'm gonna add Metal and DirectX.

## Disclaimer
I *STRONGLY* recommend using GLFW instead of this library. Neptune is highly specified to the needs of my game engine. I simply added features to allow use for small OpenGL projects. The only benefit is that it already comes equipped with OpenGL 4.1.

https://garagecrew.org/neptune

## Features
* GLFW-Style Window Creation (macOS Only)
* OpenGL 4.1 Ready
* Keyboard Input
* Callback System

## Future
* Desktop Platform Window Creation
* Cross-API Rendering (No Translation)
* Mobile Windowing??

## Compiling The Library
Neptune uses GNU Make as its build system. It currently only runs on macOS, so that is all it can compile from. To compile, use `cd` to navigate to the directory and run `make` in the terminal. The Neptune library will appear in the bin folder. If you want to compile the examples, run `make example EXAMPLE=project`, project being the name of the example file. (You can also use this to write a test project and avoid the trouble of a proper IDE)

### Neptune Colors
* Neptune Blue - 394C56
* Sandy Brown - 877158
* Moonlight Silver - 808080
