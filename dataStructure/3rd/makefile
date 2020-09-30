#!/usr/bin/make

OBJ = main.o LinkedList.o

main : $(OBJ)
	g++ -o main $^

main.o: ./src/main.cpp
	g++ -c $^

LinkedList.o: ./src/LinkedList.cpp ./inc/LinkedList.hpp
	g++ -c $<

clean: 
	rm main.o LinkedList.o
