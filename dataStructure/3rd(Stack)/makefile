#!/usr/bin/make

OBJ = main.o Stack.o

main : $(OBJ)
	g++ -o main $^

main.o : ./src/main.cpp
	g++ -c $^

Stack.o : ./src/Stack.cpp ./inc/Stack.hpp
	g++ -c $<

clean :
	rm $(OBJ)
