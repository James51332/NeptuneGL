#include "Internal.h"

#include <stdlib.h>

// ---------------------------------------------------
// ---------------------------------------------------
// ----------      NEPTUNE METHOD API       ----------
// ---------------------------------------------------
// ---------------------------------------------------

void defaultWindowHints(void)
{
  _neptune.hints.glmajor = 1;
  _neptune.hints.glminor = 0;
}

void initKeyStrings(void)
{
  _neptune.keyStrings[NEPTUNE_KEY_TAB] = "Tab";
  _neptune.keyStrings[NEPTUNE_KEY_LEFT_SHIFT] = "Left Shift";
  _neptune.keyStrings[NEPTUNE_KEY_RIGHT_SHIFT] = "Right Shift";
  _neptune.keyStrings[NEPTUNE_KEY_FUNCTION] = "Function";
  _neptune.keyStrings[NEPTUNE_KEY_CONTROL] = "Control";
  _neptune.keyStrings[NEPTUNE_KEY_LEFT_ALT] = "Left Option";
  _neptune.keyStrings[NEPTUNE_KEY_RIGHT_ALT] = "Right Option";
  _neptune.keyStrings[NEPTUNE_KEY_LEFT_COMMAND] = "Left Command";
  _neptune.keyStrings[NEPTUNE_KEY_RIGHT_COMMAND] = "Right Command";
  _neptune.keyStrings[NEPTUNE_KEY_UP] = "Up";
  _neptune.keyStrings[NEPTUNE_KEY_RIGHT] = "Right";
  _neptune.keyStrings[NEPTUNE_KEY_DOWN] = "Down";
  _neptune.keyStrings[NEPTUNE_KEY_LEFT] = "Left";
  _neptune.keyStrings[NEPTUNE_KEY_ESCAPE] = "Escape";
  _neptune.keyStrings[NEPTUNE_KEY_SPACE] = "Space";
  _neptune.keyStrings[NEPTUNE_KEY_MINUS] = "-";
  _neptune.keyStrings[NEPTUNE_KEY_COMMA] = ",";
  _neptune.keyStrings[NEPTUNE_KEY_PERIOD] = ".";
  _neptune.keyStrings[NEPTUNE_KEY_SLASH] = "/";
  _neptune.keyStrings[NEPTUNE_KEY_0] = "0";
  _neptune.keyStrings[NEPTUNE_KEY_1] = "1";
  _neptune.keyStrings[NEPTUNE_KEY_2] = "2";
  _neptune.keyStrings[NEPTUNE_KEY_3] = "3";
  _neptune.keyStrings[NEPTUNE_KEY_4] = "4";
  _neptune.keyStrings[NEPTUNE_KEY_5] = "5";
  _neptune.keyStrings[NEPTUNE_KEY_6] = "6";
  _neptune.keyStrings[NEPTUNE_KEY_7] = "7";
  _neptune.keyStrings[NEPTUNE_KEY_8] = "8";
  _neptune.keyStrings[NEPTUNE_KEY_9] = "9";
  _neptune.keyStrings[NEPTUNE_KEY_SEMICOLON] = ";";
  _neptune.keyStrings[NEPTUNE_KEY_LESS_THAN] = "<";
  _neptune.keyStrings[NEPTUNE_KEY_EQUALS] = "=";
  _neptune.keyStrings[NEPTUNE_KEY_GREATER_THAN] = ">";
  _neptune.keyStrings[NEPTUNE_KEY_A] = "A";
  _neptune.keyStrings[NEPTUNE_KEY_B] = "B";
  _neptune.keyStrings[NEPTUNE_KEY_C] = "C";
  _neptune.keyStrings[NEPTUNE_KEY_D] = "D";
  _neptune.keyStrings[NEPTUNE_KEY_E] = "E";
  _neptune.keyStrings[NEPTUNE_KEY_F] = "F";
  _neptune.keyStrings[NEPTUNE_KEY_G] = "G";
  _neptune.keyStrings[NEPTUNE_KEY_H] = "H";
  _neptune.keyStrings[NEPTUNE_KEY_I] = "I";
  _neptune.keyStrings[NEPTUNE_KEY_J] = "J";
  _neptune.keyStrings[NEPTUNE_KEY_K] = "K";
  _neptune.keyStrings[NEPTUNE_KEY_L] = "L";
  _neptune.keyStrings[NEPTUNE_KEY_M] = "M";
  _neptune.keyStrings[NEPTUNE_KEY_N] = "N";
  _neptune.keyStrings[NEPTUNE_KEY_O] = "O";
  _neptune.keyStrings[NEPTUNE_KEY_P] = "P";
  _neptune.keyStrings[NEPTUNE_KEY_Q] = "Q";
  _neptune.keyStrings[NEPTUNE_KEY_R] = "R";
  _neptune.keyStrings[NEPTUNE_KEY_S] = "S";
  _neptune.keyStrings[NEPTUNE_KEY_T] = "T";
  _neptune.keyStrings[NEPTUNE_KEY_U] = "U";
  _neptune.keyStrings[NEPTUNE_KEY_V] = "V";
  _neptune.keyStrings[NEPTUNE_KEY_W] = "W";
  _neptune.keyStrings[NEPTUNE_KEY_X] = "X";
  _neptune.keyStrings[NEPTUNE_KEY_Y] = "Y";
  _neptune.keyStrings[NEPTUNE_KEY_Z] = "Z";
  _neptune.keyStrings[NEPTUNE_KEY_LEFT_BRACKET] = "[";
  _neptune.keyStrings[NEPTUNE_KEY_BACKSLASH] = "\\";
  _neptune.keyStrings[NEPTUNE_KEY_RIGHT_BRACKET] = "]";
  _neptune.keyStrings[NEPTUNE_KEY_BACKSPACE] = "Backspace";
}

// ---------------------------------------------------
// ---------------------------------------------------
// ----------      NEPTUNE PUBLIC API       ----------
// ---------------------------------------------------
// ---------------------------------------------------

NEPTUNEAPI void neptuneWindowHint(NeptuneWindowHint hint, int val)
{
  switch (hint)
  {
  case NEPTUNE_OPENGL_VERSION_MAJOR:
    _neptune.hints.glmajor = val;
    break;
  case NEPTUNE_OPENGL_VERSION_MINOR:
    _neptune.hints.glminor = val;
    break;
  }
}

NEPTUNEAPI int neptuneInit(void)
{
  if (_neptune.initialized)
    return NEPTUNE_TRUE;

  if (platformInit())
    _neptune.initialized = NEPTUNE_TRUE;

  memset(&_neptune.callbacks, 0, sizeof(_neptune.callbacks));

  initKeyStrings();

  defaultWindowHints();

  return _neptune.initialized;
}

NEPTUNEAPI void neptuneTerminate(void)
{
  _NEPTUNE_REQUIRE_INIT();

  if (_neptune.windowListHead != NULL)
    neptuneDestroyAllWindows();

  platformTerminate();
}
