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

.SILENT:
lib:
	clang -c $(LIBFILES) $(FLAGS)
	ar rcs Neptune.a Window.o Init.o Global.o CocoaWindow.o CocoaInit.o CocoaGLContext.o
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

VERSION=0.0.0
NAME = NeptuneGL-$(VERSION)
RPATH = Releases/$(NAME)

release:
	mkdir $(RPATH)
	cp -r Include $(RPATH)/
	cp Bin/Neptune.a $(RPATH)/Neptune.a
	cp LICENSE $(RPATH)/LICENSE
	cp -r $(RPATH) $(NAME)
	zip -r -qq -X $(NAME).zip $(NAME)
	rm -R $(NAME)
