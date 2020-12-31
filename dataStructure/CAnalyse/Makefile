CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g

vpath  %.cpp src

UNAME = $(shell uname)

ifeq ($(UNAME), Linux)
vpath  %.cpp src/GNU
else
vpath  %.cpp src/win
endif

SRC = Token.cpp Lexer.cpp Parser.cpp \
Interpreter.cpp main.cpp AddressParser.cpp \
getExecDirectory.cpp FileReader.cpp\
isAbsPath.cpp isDir.cpp\

OBJ = $(SRC:.cpp=.o)
EXEC = csa

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)
