#include "../inc/Huffman.hpp"
#include <queue>
#include <vector>

/****** Node class *****/

HNode::HNode(int weight, char c, HNode * left, HNode * right, HNode * parent)
	: m_weight(weight), m_char(c), m_parent(parent), m_left(left), m_right(right) {}

HNode::~HNode() {
	if (m_left != nullptr) delete m_left;
	if (m_right != nullptr) delete m_right;
}

int HNode::getWeight() const {
	return m_weight;
}
int HNode::getChar() const {
	return m_char;
}
HNode * HNode::getParent() const {
	return m_parent;
}

/****** HuffmanEncoder class *****/

HuffmanEncoder::HuffmanEncoder(std::string text) : m_text(text) {
}

HuffmanEncoder::~HuffmanEncoder() {
}

HNode * HuffmanEncoder::encode() {
	// weight[0] for 'a', weight[1] for 'b', blabla.
	int weight[4] = {0};

	for (auto c : m_text) {

		switch (c) {
			case 'a':
				weight[0] ++ ;
				break;

			case 'b':
				weight[1] ++ ;
				break;

			case 'c':
				weight[2] ++ ;
				break;

			case 'd':
				weight[3] ++ ;
				break;
		}
	}

	auto cmp = [](HNode * pa, HNode * pb)->bool {
		return pa -> getWeight() > pb -> getWeight();
	};

	std::priority_queue<HNode*, std::vector<HNode *>, decltype(cmp)> q(cmp);

	HNode * p = new HNode(weight[0], 'a');
	q.push(p);
	p = new HNode(weight[1], 'b');
	q.push(p);
	p = new HNode(weight[2], 'c');
	q.push(p);
	p = new HNode(weight[3], 'd');
	q.push(p);
	p = nullptr;

	while (q.size() != 1) {
		HNode * p1 = q.top();
		q.pop();
		HNode * p2 = q.top();
		q.pop();

		p = new HNode(p1 -> getWeight() + p2 -> getWeight(), '#', p1, p2);

		q.push(p);
	}

	return q.top();
}
