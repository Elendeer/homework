#ifndef __BINARY_TREE__
#define __BINARY_TREE__

#include <iostream>

class BinaryTreeNode;

// alias of class BinaryTreeNode.
using Node = BinaryTreeNode;



class BinaryTreeNode {
private:

	int m_data;
	Node * m_left;
	Node * m_right;

public:
	BinaryTreeNode();
	BinaryTreeNode(int data, Node * left = nullptr, Node * right = nullptr);
	~BinaryTreeNode();


	int getData() const;
	Node * getLeft() const;
	Node * getRight() const;

	friend class BinaryTree;
};


// Previous Order Traversed Parser.
// A parser that can parse a previous order traversed string to
// a binary tree.
// Can only parse '0' ~ '9' and 'n' now.
class POT_Parser {
private:
	std::string m_str;
	int m_cur_pos;
	int m_cur_token;

	Node * createSubTree();

public:
	POT_Parser();
	POT_Parser(std::string & str);
	~POT_Parser();

	Node * parse();

	friend class BinaryTree;
};


// A visitor to visit binary tree nodes.
class Node_visitor {
private:
	
public:
	Node_visitor();
	~Node_visitor();

	void visit(Node * pnode);
};


class BinaryTree {
private:
	Node * m_root;
	POT_Parser m_parser;
	Node_visitor m_visitor;


public:
	BinaryTree();

	// Create the BinaryTree using a string that traversed by previous order.
	BinaryTree(std::string & preOrderTaverse_string);

	~BinaryTree();

	Node * getRoot() const;

	// Print the preordered trverse of this binary tree.
	void printPOT();
};

#endif
