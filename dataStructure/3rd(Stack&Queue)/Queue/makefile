#!/usr/bin/make

OBJ = main.o Queue.o

main : $(OBJ)
	g++ -o main $^

main.o : ./src/main.cpp
	g++ -c $^

Queue.o : ./src/Queue.cpp ./inc/Queue.hpp
	g++ -c $<

clean:
	rm $(OBJ)
