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
class BinaryNodeVisitor {
private:
	int m_depth, m_leaves, m_nodes;
	// m_tree for a full tree. Will be used when this -> draw().
	int * m_tree;

	void countTree(Node * pnode, int cur_depth);
public:
	BinaryNodeVisitor();
	~BinaryNodeVisitor();

	// Print the preorder visit string of the tree whose root is pnode pointing to.
	void preorderVisit(Node * pnode);
	// Print the inorder visit string of the tree whose root is pnode pointing to.
	void inorderVisit(Node * pnode);
	// Print the postorder visit string of the tree whose root is pnode pointing to.
	void postorderVisit(Node * pnode);

	// Return the depth of the tree whose root is pnode pointing to.
	int depth(Node * pnode);
	// Return the number of leaves of the tree whose root is pnode pointing to.
	int leaves(Node * pnode);
	// Return the number of node of the tree whose root is pnode pointing to.
	int nodes(Node * pnode);

	void draw(int width,Node * pnode);

	// Create a full binary tree for draw and store it in a arrary.
	// Return the arrary.
	void createFulltree(Node * root, int * array, bool * map, int idx);
};


class BinaryTree {
private:
	Node * m_root;
	POT_Parser m_parser;
	BinaryNodeVisitor m_visitor;


public:
	BinaryTree();

	// Create the BinaryTree using a string that traversed by previous order.
	BinaryTree(std::string & preOrderTaverse_string);

	~BinaryTree();

	Node * getRoot() const;

	// Print the preordered trverse of this binary tree.
	void printDLR();
	// Print the inordered trverse of this binary tree.
	void printLDR();
	// Print the postordered trverse of this binary tree.
	void printLRD();

	// Get the depth of tree.
	int getDepth();
	// Get the number leaves of tree.
	int getLeavesNum();
	// Get the number nodes of tree.
	int getNodesNum();

	// Draw a ascii picture of tree.
	void draw();

};

#endif
