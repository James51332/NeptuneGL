STATIC = ON
EXAMPLE = Window

PATH = $(shell pwd)/

LIBFILES =\
Src/Window.c \
Src/Init.c \
Src/Global.c \
Src/Cocoa/CocoaGLContext.m \
Src/Cocoa/CocoaWindow.m \
Src/Cocoa/CocoaInit.m

DEFINES =\
-D NEPTUNE_COCOA \
-D GL_SILENCE_DEPRECATION

FLAGS =\
$(DEFINES) \
-I $(PATH)include/ \
-iquote $(PATH)src/

lib:
	clang -c $(LIBFILES) $(FLAGS)
	ar -rv Neptune.a Window.o Init.o Global.o CocoaWindow.o CocoaInit.o
	find $(PATH) -name '*.o' -delete
	mv Neptune.a bin/Neptune.a

EXAMFLAGS =\
-I $(PATH)include/ \
-framework Cocoa \
-framework OpenGL \
-o $(EXAMPLE) \
-D GL_SILENCE_DEPRECATION

example:
	clang Examples/$(EXAMPLE).c Bin/Neptune.a $(EXAMFLAGS)
