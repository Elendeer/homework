#ifndef __GRAPHIC_HPP__
#define __GRAPHIC_HPP__

#include <vector>
#include <list>

class AdjNode {
private:
	// Number of ending node of edge.
	int m_num;
	// Weight of edge.
	int m_weight;
public:
	AdjNode(int num, int weight);
	~AdjNode();

	int getNum() const;
	int getWeight() const;
};

class Graphic {
private:
	// Head nodes of adjacency table.
	std::vector<std::list<AdjNode>> m_heads;
public:
	// n = number of nodes.
	Graphic(int n);
	~Graphic();

	// add a Edge into graphic.
	void addEdge(int start, int end, int weight = 0);

	void printAdjacencyTable();
};

#endif
