#include "../inc/BinaryTree.hpp"
#include <iostream>

/****** Functions of BinaryTreeNode class *****/

Node::BinaryTreeNode() :
	m_data(0), m_left(nullptr), m_right(nullptr) {
	
	std::cout << "Node created" << std::endl;
}

Node::BinaryTreeNode(int data, Node * left, Node * right) :
	m_data(data), m_left(left), m_right(right) {

	std::cout << "Node created" << std::endl;
}

Node::~BinaryTreeNode() {
	if (m_left != nullptr) delete m_left;
	if (m_right != nullptr) delete m_right;

	std::cout << "Node destoryed" << std::endl;
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


/****** Functions of POT_Parser class *****/

POT_Parser::POT_Parser() {}

POT_Parser::POT_Parser(std::string & str) :
	m_str(str), m_cur_pos(0), m_cur_token(str[0]){}

POT_Parser::~POT_Parser() {}

Node * POT_Parser::createSubTree() {
	if (m_cur_pos == m_str.size() ) return nullptr;

	int token = m_cur_token;
	if (token >= '0' && token <= '9') {
		m_cur_token = m_str[++ m_cur_pos];

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


/****** Functions of Node_visitor class *****/

Node_visitor::Node_visitor() {}
Node_visitor::~Node_visitor() {}

void Node_visitor::visit(Node * pnode) {
	std::cout << pnode->getData() << " ";
	if (pnode->getLeft() != nullptr) this -> visit(pnode->getLeft());
	else std::cout <<  "n ";
	if (pnode->getRight() != nullptr) this -> visit(pnode->getRight());
	else std::cout <<  "n ";
}



/****** Functions of BinaryTree class *****/

BinaryTree::BinaryTree() : m_root(nullptr) {}

BinaryTree::BinaryTree(std::string & preOrderTaverse_string) {
	m_parser = POT_Parser(preOrderTaverse_string);
	m_root = m_parser.parse();

	std::cout << "tree created" << std::endl;
}

BinaryTree::~BinaryTree() {
	delete m_root;
	std::cout << "tree destoryed" << std::endl;
}

Node * BinaryTree::getRoot() const {
	return m_root;
}

void BinaryTree::printPOT() {
	this -> m_visitor.visit(m_root);
	std::cout << std::endl;
}
