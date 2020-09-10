#!/usr/bin/make

main: main.o Complex.o
	g++ main.o Complex.o -o main

main.o: ./src/main.cpp
	g++ -c ./src/main.cpp

Complex.o: ./src/Complex.cpp
	g++ -c ./src/Complex.cpp

clean:
	rm main.o Complex.o
