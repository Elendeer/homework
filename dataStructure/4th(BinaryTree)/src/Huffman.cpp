/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-12-12 17:23:28
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-12 18:24:19
 * @Description  :
*********************************************/
#include "../inc/Huffman.hpp"
#include <queue>
#include <vector>
#include <iostream>

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
HNode * HNode::getLeft() const {
	return m_left;
}
HNode * HNode::getRight() const {
	return m_right;
}

void HNode::setParent(HNode * parent) {
	m_parent = parent;
}

/****** HuffmanEncoder class *****/

void HuffmanEncoder::dfs(HNode * p) {
	using std::cout;
	using std::endl;

	if (p -> getChar() != '#') {
		cout << (char)p -> getChar() << " : ";

		for (auto i : m_encode) {
			cout << i;
		}
		cout << endl;
	}

	if (p -> getLeft() != nullptr) {
		m_encode.push_back(0);
		dfs(p -> getLeft());
		m_encode.pop_back();
	}
	if (p -> getRight() != nullptr) {
		m_encode.push_back(1);
		dfs(p -> getRight());
		m_encode.pop_back();
	}
}

HuffmanEncoder::HuffmanEncoder(std::string text) : m_text(text) , m_root(nullptr) {
}

HuffmanEncoder::~HuffmanEncoder() {
	if (m_root != nullptr) delete m_root;
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

		p1->setParent(p);
		p2->setParent(p);

		q.push(p);
	}

	m_root = q.top();

	dfs(m_root);

	return q.top();
}
