#include "../inc/BinaryTree.hpp"
#include <iostream>
#include <queue>

/**********************************************/
/****** Functions of BinaryTreeNode class *****/
/**********************************************/

Node::BinaryTreeNode() :
	m_data(0), m_left(nullptr), m_right(nullptr) {
	
	std::cout << "Node created" << std::endl;
}

Node::BinaryTreeNode(int data, Node * left, Node * right) :
	m_data(data), m_left(left), m_right(right) {

	std::cout << "Node created : " << m_data << std::endl;
}

Node::~BinaryTreeNode() {
	if (m_left != nullptr) delete m_left;
	if (m_right != nullptr) delete m_right;

	std::cout << "Node destoryed : " << m_data << std::endl;
}

int Node::getData() const {
	return m_data;
}

Node * BinaryTreeNode::getLeft() const {
	return m_left;
}
Node * BinaryTreeNode::getRight() const {
	return m_right;
}


/**********************************************/
/****** Functions of POT_Parser class *****/
/**********************************************/

POT_Parser::POT_Parser() {}

POT_Parser::POT_Parser(std::string & str) :
	m_str(str), m_cur_pos(0), m_cur_token(str[0]){
	// std::cout << str << std::endl;
	// std::cout << m_str << std::endl;
}

POT_Parser::~POT_Parser() {}

Node * POT_Parser::createSubTree() {
	if (m_cur_pos == m_str.size() ) return nullptr;

	int token = m_cur_token;
	m_cur_token = m_str[++ m_cur_pos];
	if (token >= '0' && token <= '9') {
		Node * left = createSubTree();
		Node * right = createSubTree();
		Node * node = new Node(token - '0', left, right);

		return node;
	}
	else if (token == 'n') {
		return nullptr;
	}
	else {
		throw "error";
	}
}

Node * POT_Parser::parse() {
	return this -> createSubTree();
}


/**********************************************/
/****** Functions of BinaryNodeVisitor class *****/
/**********************************************/

BinaryNodeVisitor::BinaryNodeVisitor() : m_depth(0), m_leaves(0), m_nodes(0) {}
BinaryNodeVisitor::~BinaryNodeVisitor() {}

void BinaryNodeVisitor::preorderVisit(Node * pnode) {
	std::cout << pnode->getData() << " ";
	if (pnode->getLeft() != nullptr) this -> preorderVisit(pnode->getLeft());
	else std::cout <<  "n ";
	if (pnode->getRight() != nullptr) this -> preorderVisit(pnode->getRight());
	else std::cout <<  "n ";
}
void BinaryNodeVisitor::inorderVisit(Node * pnode) {
	if (pnode->getLeft() != nullptr) this -> inorderVisit(pnode->getLeft());
	else std::cout <<  "n ";
	std::cout << pnode->getData() << " ";
	if (pnode->getRight() != nullptr) this -> inorderVisit(pnode->getRight());
	else std::cout <<  "n ";
}
void BinaryNodeVisitor::postorderVisit(Node * pnode) {
	if (pnode->getLeft() != nullptr) this -> postorderVisit(pnode->getLeft());
	else std::cout <<  "n ";
	if (pnode->getRight() != nullptr) this -> postorderVisit(pnode->getRight());
	else std::cout <<  "n ";
	std::cout << pnode->getData() << " ";
}

void BinaryNodeVisitor::countTree(Node * pnode, int cur_depth) {
	if (pnode->getLeft() == nullptr &&
		pnode->getRight() == nullptr) {

		m_leaves ++;
		m_nodes ++;
		
		if (cur_depth > m_depth) {
			m_depth = cur_depth;
			return;
		}
	}

	m_nodes ++;

	if (pnode->getLeft() != nullptr) {
		this->countTree(pnode->getLeft(), cur_depth + 1);
	}

	if (pnode->getRight() != nullptr) {
		this->countTree(pnode->getRight(), cur_depth + 1);
	}
}

int BinaryNodeVisitor::depth(Node * pnode) {
	m_depth = 0;
	m_leaves = 0;
	m_nodes = 0;

	this->countTree(pnode, 1);
	return m_depth;
}
int BinaryNodeVisitor::leaves(Node * pnode) {
	m_depth = 0;
	m_leaves = 0;
	m_nodes = 0;

	this->countTree(pnode, 1);
	return m_leaves;
}
int BinaryNodeVisitor::nodes(Node * pnode) {
	m_depth = 0;
	m_leaves = 0;
	m_nodes = 0;

	this->countTree(pnode, 1);
	return m_nodes;
}

void BinaryNodeVisitor::draw(int depth, Node * pnode) {
	using std::cout;
	using std::endl;

	// Equal ratio sequence summation formula.

	int length = 1;
	for (int i = 1; i <= depth; ++ i ) {
		length *= 2;
	}
	// length -= 1;

	int * array = new int [length];
	bool * map = new bool [length];

	this -> createFulltree(pnode, array, map, 1);


	int width = 1;
	for (int i = 1; i <= depth; ++ i) {
		width *= 2;
	}
	int pre_width = width / 2 - 1;

	for (int i = 1; i <= depth; ++ i) {
		// Count the start index of i-th layer of the tree.
		int idx = 1;
		for (int j = 1; j < i; ++ j) {
			idx *= 2;
		}

		// Avoid the first line.
		if (i != 1) {
			// Print the pre-tabs for formating.
			for (int j = 1; j <= width / 2 - 1; ++ j) {
				cout << "\t";
			}

			// Enumerate each node of current layer.
			for (int j = idx / 2; j < idx; ++ j) {

				// Left child exist, rigth child exist.
				if (map[j * 2] && map [j * 2 + 1]) {
					cout << "/-------";
					for (int k = 1; k <= width / 2 - 1; ++k) {
						cout << "--------";
					}

					cout << "^-------";

					for (int k = 1; k <= width / 2 - 1; ++k) {
						cout << "--------";
					}
					cout << "\\";
				}

				// Left child exist, rigth child does not exist.
				else if (map[j * 2] && !map [j * 2 + 1]) {
					cout << "/-------";
					for (int k = 1; k <= width / 2 - 1; ++ k) {
						cout << "--------";
					}
					cout << "^";

					for (int k = 1; k <= width / 2; ++ k) {
						cout << "\t";
					}
				}

				// Left child does not exist, rigth child exist.
				else if (!map[j * 2] && map [j * 2 + 1]) {
					for (int k = 1; k <= width / 2; ++ k) {
						cout << "\t";
					}

					cout << "^-------";
					for (int k = 1; k <= width / 2 - 1; ++ k) {
						cout << "--------";
					}
					cout << "\\";
				}

				// Left child does not exist, rigth child does not exist.
				else if (!map[j * 2] && !map [j * 2 + 1]) {
					for (int k = 1; k <= width; ++ k) {
						cout << "\t";
					}
				}

				// Print the interval between nodes in current layer.
				for (int k = 1; k <= width; ++ k) {
					cout << "\t";
				}
			}
			cout << endl;

		}
		// cout << endl;
		// cout << width << " " << pre_width;
		// cout << endl;

		// Print the i-th layer of the tree.

		for (int j = 1; j <= pre_width; ++ j) {
			cout << "\t" ;
		}

		for (int j = idx; j < idx * 2; ++ j) {
			if (map[j]) cout << array[j];

			for (int k = 1; k <= width; ++ k) {
				cout << "\t" ;
			}
		}
		width /= 2;
		pre_width = width / 2 - 1;
		cout << endl;
	}

	cout << endl;
}

void BinaryNodeVisitor::createFulltree(Node * pnode, int * array, bool * map, int idx) {
	if (pnode == nullptr) return;

	array[idx] = pnode ->getData();
	map[idx] = true;

	createFulltree(pnode -> getLeft(), array, map, idx * 2);
	createFulltree(pnode -> getRight(), array, map, idx * 2 + 1);
}



/**********************************************/
/****** Functions of BinaryTree class *****/
/**********************************************/

BinaryTree::BinaryTree() : m_root(nullptr) {}

BinaryTree::BinaryTree(std::string & preOrderTaverse_string) {
	m_parser = POT_Parser(preOrderTaverse_string);
	m_root = m_parser.parse();

	// std::cout << preOrderTaverse_string << std::endl;
	std::cout << "tree created" << std::endl;
}

BinaryTree::~BinaryTree() {
	delete m_root;
	std::cout << "tree destoryed" << std::endl;
}

Node * BinaryTree::getRoot() const {
	return m_root;
}

void BinaryTree::printDLR() {
	this -> m_visitor.preorderVisit(m_root);
	std::cout << std::endl;
}

void BinaryTree::printLDR() {
	this -> m_visitor.inorderVisit(m_root);
	std::cout << std::endl;
}

void BinaryTree::printLRD() {
	this -> m_visitor.postorderVisit(m_root);
	std::cout << std::endl;
}

int BinaryTree::getDepth() {
	return m_visitor.depth(m_root);
}
int BinaryTree::getLeavesNum() {
	return m_visitor.leaves(m_root);
}
int BinaryTree::getNodesNum() {
	return m_visitor.nodes(m_root);
}

void BinaryTree::draw() {
	int depth = m_visitor.depth(m_root);
	
	// int width = 1;
	// for (int i = 1; i < depth; ++ i) {
	// 	width *= 2;
	// }
	// std::cout << width << std::endl;

	this -> m_visitor.draw(depth, m_root);
}
