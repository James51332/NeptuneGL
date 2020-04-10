#ifdef NEPTUNE_COCOA

#include <crt_externs.h>

#include "Internal.h"

// ---------------------------------------------------
// ---------------------------------------------------
// ----------      NEPTUNE METHOD API       ----------
// ---------------------------------------------------
// ---------------------------------------------------

void keyCodeInit(void) {
  //Set all values to unknown unless we specify otherwise
  memset(_neptune.ns.keyCode, NEPTUNE_KEY_UNKNOWN, sizeof(_neptune.ns.keyCode));

  //Write in hex for efficiency (out of order due to qwerty) Credit to
  //https://developer.apple.com/library/archive/documentation/mac/pdf/MacintoshToolboxEssentials.pdf (pg. 86 / 909)
  //for keyCodes
  _neptune.ns.keyCode[0x30] = NEPTUNE_KEY_TAB;
  _neptune.ns.keyCode[0x7e] = NEPTUNE_KEY_UP;
  _neptune.ns.keyCode[0x7c] = NEPTUNE_KEY_RIGHT;
  _neptune.ns.keyCode[0x7d] = NEPTUNE_KEY_DOWN;
  _neptune.ns.keyCode[0x7b] = NEPTUNE_KEY_LEFT;

  _neptune.ns.keyCode[0x35] = NEPTUNE_KEY_ESCAPE;
  _neptune.ns.keyCode[0x31] = NEPTUNE_KEY_SPACE;
  _neptune.ns.keyCode[0x1b] = NEPTUNE_KEY_MINUS;
  _neptune.ns.keyCode[0x2b] = NEPTUNE_KEY_COMMA;
  _neptune.ns.keyCode[0x2f] = NEPTUNE_KEY_PERIOD;
  _neptune.ns.keyCode[0x2c] = NEPTUNE_KEY_SLASH;

  _neptune.ns.keyCode[0x1D] = NEPTUNE_KEY_0;
  _neptune.ns.keyCode[0x12] = NEPTUNE_KEY_1;
  _neptune.ns.keyCode[0x13] = NEPTUNE_KEY_2;
  _neptune.ns.keyCode[0x14] = NEPTUNE_KEY_3;
  _neptune.ns.keyCode[0x15] = NEPTUNE_KEY_4;
  _neptune.ns.keyCode[0x17] = NEPTUNE_KEY_5;
  _neptune.ns.keyCode[0x16] = NEPTUNE_KEY_6;
  _neptune.ns.keyCode[0x1A] = NEPTUNE_KEY_7;
  _neptune.ns.keyCode[0x1C] = NEPTUNE_KEY_8;
  _neptune.ns.keyCode[0x19] = NEPTUNE_KEY_9;

  _neptune.ns.keyCode[0x00] = NEPTUNE_KEY_A;
  _neptune.ns.keyCode[0x0B] = NEPTUNE_KEY_B;
  _neptune.ns.keyCode[0x08] = NEPTUNE_KEY_C;
  _neptune.ns.keyCode[0x02] = NEPTUNE_KEY_D;
  _neptune.ns.keyCode[0x0E] = NEPTUNE_KEY_E;
  _neptune.ns.keyCode[0x03] = NEPTUNE_KEY_F;
  _neptune.ns.keyCode[0x05] = NEPTUNE_KEY_G;
  _neptune.ns.keyCode[0x04] = NEPTUNE_KEY_H;
  _neptune.ns.keyCode[0x22] = NEPTUNE_KEY_I;
  _neptune.ns.keyCode[0x26] = NEPTUNE_KEY_J;
  _neptune.ns.keyCode[0x28] = NEPTUNE_KEY_K;
  _neptune.ns.keyCode[0x25] = NEPTUNE_KEY_L;
  _neptune.ns.keyCode[0x2E] = NEPTUNE_KEY_M;
  _neptune.ns.keyCode[0x2D] = NEPTUNE_KEY_N;
  _neptune.ns.keyCode[0x1F] = NEPTUNE_KEY_O;
  _neptune.ns.keyCode[0x23] = NEPTUNE_KEY_P;
  _neptune.ns.keyCode[0x0C] = NEPTUNE_KEY_Q;
  _neptune.ns.keyCode[0x0F] = NEPTUNE_KEY_R;
  _neptune.ns.keyCode[0x01] = NEPTUNE_KEY_S;
  _neptune.ns.keyCode[0x11] = NEPTUNE_KEY_T;
  _neptune.ns.keyCode[0x20] = NEPTUNE_KEY_U;
  _neptune.ns.keyCode[0x09] = NEPTUNE_KEY_V;
  _neptune.ns.keyCode[0x0D] = NEPTUNE_KEY_W;
  _neptune.ns.keyCode[0x07] = NEPTUNE_KEY_X;
  _neptune.ns.keyCode[0x10] = NEPTUNE_KEY_Y;
  _neptune.ns.keyCode[0x06] = NEPTUNE_KEY_Z;

  _neptune.ns.keyCode[0x21] = NEPTUNE_KEY_LEFT_BRACKET;
  _neptune.ns.keyCode[0x2a] = NEPTUNE_KEY_BACKSLASH;
  _neptune.ns.keyCode[0x1e] = NEPTUNE_KEY_RIGHT_BRACKET;
  _neptune.ns.keyCode[0x33] = NEPTUNE_KEY_BACKSPACE;
}

void createMenuBar(void) {
  //Get application title
  NSDictionary* plist = [[NSBundle mainBundle] infoDictionary];
  NSString* title = plist[@"CFBundleName"];

  if (!title) {
    char** temp = _NSGetProgname();
    if (temp && *temp)
      title = [NSString stringWithUTF8String:*temp];
    else
      title = @"Neptune Application";
  }

  _neptune.ns.menu = [[NSMenu alloc] init];
  [NSApp setMainMenu:_neptune.ns.menu];

  NSMenuItem* menuItem = [_neptune.ns.menu addItemWithTitle:@"" action:NULL keyEquivalent:@""];

  NSMenu* dropMenu = [[NSMenu alloc] init];
  [menuItem setSubmenu:dropMenu];

  [dropMenu  addItemWithTitle: [NSString stringWithFormat:@"About %@", title]
                       action: @selector(orderFrontStandardAboutPanel:)
                keyEquivalent: @""];

  [dropMenu addItem: [NSMenuItem separatorItem]];

  [dropMenu  addItemWithTitle: [NSString stringWithFormat:@"Hide %@", title]
                       action: @selector(hide:)
                keyEquivalent: @"h"];

  [[dropMenu addItemWithTitle: @"Hide Others"
                       action: @selector(hideOtherApplications:)
                keyEquivalent: @"h"]
  setKeyEquivalentModifierMask:NSEventModifierFlagOption | NSEventModifierFlagCommand];

  [dropMenu  addItemWithTitle: @"Show All"
                       action: @selector(unhideAllApplications:)
                keyEquivalent: @""];

  [dropMenu addItem: [NSMenuItem separatorItem]];

  [dropMenu addItemWithTitle: [NSString stringWithFormat:@"Quit %@", title]
                      action: @selector(terminate:)
               keyEquivalent: @"q"];
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

    //Allow input on unbundled executables
    [NSApp setActivationPolicy: NSApplicationActivationPolicyRegular];

    keyCodeInit();

    createMenuBar();

    if (!NSApp)
      return NEPTUNE_FALSE;
    else
      return NEPTUNE_TRUE;
  }
}

void platformTerminate(void) {
  [NSApp terminate: nil];
}

#endif
