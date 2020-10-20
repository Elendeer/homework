#!/usr/bin/make

OBJ = ./main.o ./Calculator.o

main : $(OBJ)
	g++ -o main $^

main.o : ./src/main.cpp
	g++ -c $^

Calculator.o : ./src/Calculator.cpp ./inc/Calculator.hpp
	g++ -c $<

clean :
	rm $(OBJ)
