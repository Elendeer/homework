#!/usr/bin/make

CXX := g++
CXXFLAGS := -Wall -Werror -Wextra -pedantic -std=c++11 -g

vpath %.cc src
vpath %.h inc

OBJ := main.o UIDisplayer.o ReaderSystem.o
EXEC := main

$(EXEC) : $(OBJ) SingleLinkedList.h
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

main.o : main.cc
	$(CXX) $(CXXFLAGS) -c $<

UIDisplayer.o : UIDisplayer.cc UIDisplayer.h
	$(CXX) $(CXXFLAGS) -c $<

ReaderSystem.o : ReaderSystem.cc ReaderSystem.h
	$(CXX) $(CXXFLAGS) -c $<


.phony : clean

clean :
	rm -rf $(OBJ) $(EXEC)