#!/usr/bin/make

CXX := g++
CXXFLAGS := -Wall -Werror -Wextra -pedantic -std=c++11 -g

vpath %.cc src
vpath %.h inc

OBJ := main.o chromosome.o chromosome_set.o
EXEC := main

$(EXEC) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

main.o : main.cc
	$(CXX) $(CXXFLAGS) -c $<

chromosome.o : chromosome.cc chromosome.h
	$(CXX) $(CXXFLAGS) -c $<

chromosome_set.o : chromosome_set.cc chromosome_set.h
	$(CXX) $(CXXFLAGS) -c $<

.PHONY : clean

clean :
	rm -rf $(OBJ) $(EXEC)