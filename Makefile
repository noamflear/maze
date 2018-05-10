all: maze.o
	g++ maze.o -o main

maze:	
	g++ maze.cpp -c maze.o


