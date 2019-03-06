MAINFILENAME=main.cpp
LIBS=-lGL -lGLU -lX11 -lglut -lpthread -lpng
MAINMICFILENAME=micmain
MCU=atmega2560
CFLAGS=-O3 -Wall 
FILES=baseGlObj.cpp view.cpp button.cpp

all: main

main:
	g++ $(CFLAGS) $(LIBS) "$(MAINFILENAME)" $(FILES) -o ./run

debug:
	g++ $(LIBS) $(CFLAGS) -g "$(MAINFILENAME)" $(FILES) -Og -o ./run

run: main
	./run
