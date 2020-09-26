#!/usr/bin/make

main: main.o LinearList.o
	g++ main.o LinearList.o -o main

main.o: ./src/main.cpp
	g++ -c ./src/main.cpp

LinearList.o: ./src/LinearList.cpp ./inc/LinearList.hpp
	g++ -c ./src/LinearList.cpp

clean:
	rm main.o LinearList.o
