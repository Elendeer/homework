#!/usr/bin/make

CXX = g++
CXXFLAGES = -Wall -Werror -Wextra -pedantic -std=c++17 -g

vpath %.cpp src
SRC = main.cpp Token.cpp Lexer.cpp Parser.cpp Interpreter.cpp AddressParser.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = main

all : $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $@ $(OBJ) $(LBLIBS)

clean :
	rm -rf $(OBJ) $(EXEC)


