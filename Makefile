STATIC = ON
EXAMPLE = Triangle

PATH = $(shell pwd)/

LIBFILES =\
Src/Window.c \
Src/Init.c \
Src/Global.c \
Src/Event.c \
Src/Utility.c \
Src/Context.c \
Src/Cocoa/CocoaGLContext.m \
Src/Cocoa/CocoaWindow.m \
Src/Cocoa/CocoaInit.m \
Src/Cocoa/CocoaEvent.m

DEFINES =\
-D NEPTUNE_COCOA \
-D GL_SILENCE_DEPRECATION

FLAGS =\
$(DEFINES) \
-I $(PATH)include/ \
-iquote $(PATH)src/

OBJFILES = $(shell )

.SILENT:
lib:
	clang -c $(LIBFILES) $(FLAGS)
	ar rcs Neptune.a Window.o Init.o Global.o Event.o Utility.o Context.o CocoaEvent.o CocoaGLContext.o CocoaWindow.o CocoaInit.o
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
	mv $(RPATH) $(NAME)
	zip -r -qq -X $(NAME).zip $(NAME)
	mv $(NAME).zip $(RPATH).zip
	rm -R $(NAME)
