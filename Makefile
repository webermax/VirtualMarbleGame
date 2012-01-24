LINKYLIBS=-lGL -lGLU -lglut  -lopencv_core -lopencv_imgproc -lopencv_highgui
CXXFLAGS=-O2 -march=native -pipe

build:	Game.o Graphics.o Labyrinth.o Marble.o VideoManager.o
	g++ ${LINKYLIBS} ${CXXFLAGS} -o bin/Game Graphics.o Game.o Marble.o Labyrinth.o VideoManager.o

Game.o:	
	g++ ${LINKYLIBS} -c Game.cpp

Graphics.o:	
	g++ ${LINKYLIBS} -c Graphics.cpp

Labyrinth.o:	
	g++ ${LINKYLIBS} -c Labyrinth.cpp

Marble.o:	
	g++ ${LINKYLIBS} -c Marble.cpp

VideoManager.o:	
	g++ ${LINKYLIBS} -c VideoManager.cpp

clean:	
	rm *.o bin/*

