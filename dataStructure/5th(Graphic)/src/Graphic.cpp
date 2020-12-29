#include "../inc/Graphic.hpp"
#include <iostream>

/****** AdjNode Class ******/

AdjNode::AdjNode(int num, int weight) : m_num(num), m_weight(weight) {}
AdjNode::~AdjNode() {}

int AdjNode::getNum() const {
	return m_num;
}
int AdjNode::getWeight() const {
	return m_weight;
}


/****** Graphic Class ******/

Graphic::Graphic(int n) {
	// Init adjacency list.
	m_heads.reserve(n + 1);
	// Appointment : -1 is null.
	for (int i = 0; i <= n; ++ i ) {
		m_heads.push_back({AdjNode(-1, -1)});
	}
}

Graphic::~Graphic() {
}

void Graphic::addEdge(int start, int end, int weight) {
	m_heads[start].push_front(AdjNode(end, weight));
}

void Graphic::printAdjacencyTable() {
	using std::cout;
	using std::endl;

	cout << "Heads\tlist --->" << endl;
	for (int i = 1; i < m_heads.size(); ++ i ) {
		cout << i << "\t" ;
		for (auto node : m_heads[i]) {
			cout << node.getNum() << "\t" ;
		}
		cout << endl;
	}
}
