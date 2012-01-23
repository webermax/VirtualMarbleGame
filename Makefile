LINKYLIBS=-lGL -lGLU -lglut  -lopencv_core -lopencv_imgproc -lopencv_highgui

build:	Game.o Graphics.o Labyrinth.o Marble.o VideoManager.o
	g++ ${LINKYLIBS} -o bin/Game Graphics.o Game.o Marble.o Labyrinth.o VideoManager.o

Game.o:	
	g++ -c Game.cpp

Graphics.o:	
	g++ -c Graphics.cpp

Labyrinth.o:	
	g++ -c Labyrinth.cpp

Marble.o:	
	g++ -c Marble.cpp

VideoManager.o:	
	g++ -c VideoManager.cpp

clean:	
	rm *.o bin/*

