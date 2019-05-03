TARGET=main
LIBS=-lGL -lGLU -lX11 -lglut -lpthread -lpng -lftgl
OPTIMIZE=-Og
CFLAGS=$(OPTIMIZE) -Wall -Wextra -g
LFLAGS=-Wall -Wextra -lm
CPP=g++
LD=ld
BUILDDIR=Build
SOURCEDIR=Src
BINDIR=Binaries




all: $(BUILDDIR)/$(TARGET)

$(BUILDDIR)/$(TARGET): $(BUILDDIR)/$(TARGET).o
	$(CPP) $(LFLAGS) $(LIBS) $(BUILDDIR)/baseGlObj.o $(BUILDDIR)/view.o $(BUILDDIR)/$(TARGET).o -o $(BINDIR)/$(TARGET)

$(BUILDDIR)/$(TARGET).o: $(BUILDDIR)/baseGlObj.o $(BUILDDIR)/view.o
	$(CPP) -c $(CFLAGS) $(SOURCEDIR)/$(TARGET).cpp -o $(BUILDDIR)/$(TARGET).o

$(BUILDDIR)/baseGlObj.o:
	$(CPP) -c $(CFLAGS) $(SOURCEDIR)/baseGlObj.cpp -o $(BUILDDIR)/baseGlObj.o

$(BUILDDIR)/view.o:
	$(CPP) -c $(CFLAGS) $(SOURCEDIR)/view.cpp -o $(BUILDDIR)/view.o


clean:
	rm -rf $(BUILDDIR)/*

run: main
	./run
