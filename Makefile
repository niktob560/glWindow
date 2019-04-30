TARGET=main
LIBS=-lGL -lGLU -lX11 -lglut -lpthread -lpng -lftgl
OPTIMIZE=-O3
CFLAGS=$(OPTIMIZE) -Wall -Wextra
LFLAGS=-Wall -Wextra -lm
CPP=g++
LD=ld
BUILDDIR=Build
SOURCEDIR=Src




all: $(BUILDDIR)/$(TARGET)

$(BUILDDIR)/$(TARGET): $(BUILDDIR)/$(TARGET).o
	$(CPP) $(LFLAGS) $(BUILDDIR)/$(TARGET).o -o $(BUILDDIR)/$(TARGET)

$(BUILDDIR)/$(TARGET).o:
	$(CPP) -c $(CFLAGS) $(SOURCEDIR)/$(TARGET).cpp -o $(BUILDDIR)/$(TARGET).o


debug:
	$(CPP) $(LIBS) $(CFLAGS) -g "$(TARGET)" -Og -o ./run

clean:
	rm -rf $(BUILDDIR)/*

run: main
	./run
