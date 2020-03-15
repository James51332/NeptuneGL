#ifndef CocoaPlatform_h
#define CocoaPlatform_h

//Cocoa native window type
typedef struct NeptuneWindowNS {
  id object;
  id delegate;

} NeptuneWindowNS;

//platform window creation macro
#define _NEPTUNE_PLATFORM_WINDOW_CONTEXT NeptuneWindowNS ns

#endif /* end of include guard: CocoaPlatform_h */
