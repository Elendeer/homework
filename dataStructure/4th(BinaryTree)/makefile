CXX = g++
CXXFLAGES = -Wall -Werror -Wextra -pedantic -std=c++17 -g

vpath %.cpp src
SRC = main.cpp BinaryTree.cpp Huffman.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = main

all : $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $@ $(OBJ) $(LBLIBS) # $@ means the full name of objects, which mean EXEC here.

clean :
	rm -rf $(OBJ) $(EXEC)
