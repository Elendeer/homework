CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g

vpath  %.cpp src
vpath  %.cpp src/win
vpath  %.cpp src/GNU

define SRC
Token.cpp Lexer.cpp Parser.cpp
Interpreter.cpp main.cpp AddressParser.cpp
getExecDirectory.cpp FileReader.cpp isAbsPath.cpp
endef

OBJ = $(SRC:.cpp=.o)
EXEC = csa

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)