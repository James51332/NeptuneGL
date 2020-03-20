#include "Internal.h"

//Create a static variable to store the states and values of the library
//This allows us to not require values for certain functions such as
//neptuneDestroyAllWindows();
_NeptuneLibrary _neptune = { NEPTUNE_FALSE };
