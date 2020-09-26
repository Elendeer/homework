#!/usr/bin/make

main : main.o LinkedList.o
	g++ main.o LinkedList.o -o main

main.o: ./src/main.cpp
	g++ -c ./src/main.cpp

LinkedList.o: ./src/LinkedList.cpp ./inc/LinkedList.hpp
	g++ -c ./src/LinkedList.cpp

clean: 
	rm main.o LinkedList.o
