#COMPILER VARIABLES
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11

bst: bst.o
	$(CXX) $(CXXFLAGS) bst.o -o bst

bst.o: bst.cc
	$(CXX) $(CXXFLAGS) -c bst.cc

clean:
	rm *.o bst

