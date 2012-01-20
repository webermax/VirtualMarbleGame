build:	Game.o Graphics.o Labyrinth.o Marble.o
	g++ -lGL -lGLU -lglut -o bin/Game Graphics.o Game.o Marble.o Labyrinth.o

Game.o:	
	g++ -lGL -lGLU -lglut -c Game.cpp

Graphics.o:	
	g++ -lGL -lGLU -lglut -c Graphics.cpp

Labyrinth.o:	
	g++ -lGL -lGLU -lglut -c Labyrinth.cpp

Marble.o:	
	g++ -lGL -lGLU -lglut -c Marble.cpp

clean:	
	rm *.o bin/*


