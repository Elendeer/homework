#include <iostream>
#include "../inc/Graphic.hpp"

int main() {
	using namespace std;
	Graphic g(5);

	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(2, 8);
	g.addEdge(1, 4);
	g.addEdge(5, 4);

	g.printAdjacencyTable();
	


	return 0;
}
