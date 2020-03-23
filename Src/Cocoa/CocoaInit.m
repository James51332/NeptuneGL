#ifdef NEPTUNE_COCOA

#include "Internal.h"

// ---------------------------------------------------
// ---------------------------------------------------
// ----------      NEPTUNE METHOD API       ----------
// ---------------------------------------------------
// ---------------------------------------------------

void keyCodeInit(void) {
  //Set all values to unless we specify otherwise
  memset(_neptune.ns.keyCodes, NEPTUNE_KEY_UNKNOWN, sizeOf(_neptune.ns.keyCodes));

  //Write in hex for efficiency (out of order due to qwerty)
  //Credit to
  //https://developer.apple.com/library/archive/documentation/mac/pdf/MacintoshToolboxEssentials.pdf (pg. 86 / 909)
  //for keycodes
  _neptune.ns.keycodes[0x00] = NEPTUNE_KEY_A;
  _neptune.ns.keycodes[0x0B] = NEPTUNE_KEY_B;
  _neptune.ns.keycodes[0x08] = NEPTUNE_KEY_C;
  _neptune.ns.keycodes[0x02] = NEPTUNE_KEY_D;
  _neptune.ns.keycodes[0x0E] = NEPTUNE_KEY_E;
  _neptune.ns.keycodes[0x03] = NEPTUNE_KEY_F;
  _neptune.ns.keycodes[0x05] = NEPTUNE_KEY_G;
  _neptune.ns.keycodes[0x04] = NEPTUNE_KEY_H;
  _neptune.ns.keycodes[0x22] = NEPTUNE_KEY_I;
  _neptune.ns.keycodes[0x26] = NEPTUNE_KEY_J;
  _neptune.ns.keycodes[0x28] = NEPTUNE_KEY_K;
  _neptune.ns.keycodes[0x25] = NEPTUNE_KEY_L;
  _neptune.ns.keycodes[0x2E] = NEPTUNE_KEY_M;
  _neptune.ns.keycodes[0x2D] = NEPTUNE_KEY_N;
  _neptune.ns.keycodes[0x1F] = NEPTUNE_KEY_O;
  _neptune.ns.keycodes[0x23] = NEPTUNE_KEY_P;
  _neptune.ns.keycodes[0x0C] = NEPTUNE_KEY_Q;
  _neptune.ns.keycodes[0x0F] = NEPTUNE_KEY_R;
  _neptune.ns.keycodes[0x01] = NEPTUNE_KEY_S;
  _neptune.ns.keycodes[0x11] = NEPTUNE_KEY_T;
  _neptune.ns.keycodes[0x20] = NEPTUNE_KEY_U;
  _neptune.ns.keycodes[0x09] = NEPTUNE_KEY_V;
  _neptune.ns.keycodes[0x0D] = NEPTUNE_KEY_W;
  _neptune.ns.keycodes[0x07] = NEPTUNE_KEY_X;
  _neptune.ns.keycodes[0x10] = NEPTUNE_KEY_Y;
  _neptune.ns.keycodes[0x06] = NEPTUNE_KEY_Z;

  _neptune.ns.keycodes[0x1D] = NEPTUNE_KEY_0;
  _neptune.ns.keycodes[0x12] = NEPTUNE_KEY_1;
  _neptune.ns.keycodes[0x13] = NEPTUNE_KEY_2;
  _neptune.ns.keycodes[0x14] = NEPTUNE_KEY_3;
  _neptune.ns.keycodes[0x15] = NEPTUNE_KEY_4;
  _neptune.ns.keycodes[0x17] = NEPTUNE_KEY_5;
  _neptune.ns.keycodes[0x16] = NEPTUNE_KEY_6;
  _neptune.ns.keycodes[0x1A] = NEPTUNE_KEY_7;
  _neptune.ns.keycodes[0x1C] = NEPTUNE_KEY_8;
  _neptune.ns.keycodes[0x19] = NEPTUNE_KEY_9;
}

// ---------------------------------------------------
// ---------------------------------------------------
// ----------     NEPTUNE PLATFORM API      ----------
// ---------------------------------------------------
// ---------------------------------------------------

NeptuneBool platformInit(void) {
  @autoreleasepool {
    //Define an application on macOS
    [NSApplication sharedApplication];

    keyCodeInit();

    if (!NSApp)
      return NEPTUNE_FALSE;
    else
      return NEPTUNE_TRUE;
  }
}

void platformTerminate(void) {
  @autoreleasepool {
    [NSApp terminate: nil];
  }
}

#endif
