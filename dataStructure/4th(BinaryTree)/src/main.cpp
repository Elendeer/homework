#include <iostream>
#include "../inc/BinaryTree.hpp"
#include "../inc/Huffman.hpp"


int main() {
	using namespace std;

	string s = "123nn3n4nn345nn6nnnn";
	BinaryTree t(s);

	cout << "Preorder Taversed: ";
	t.printDLR();
	cout << "Inorder Taversed: ";
	t.printLDR();
	cout << "Postorder Taversed: ";
	t.printLRD();

	cout << "Depth: " << t.getDepth() << endl;
	cout << "Leaves: " << t.getLeavesNum() << endl;
	cout << "Nodes: " << t.getNodesNum() << endl;

	cout << "Visualization:" << endl;
	t.draw();


	// string hs = "abbcccddddd";
	// HuffmanEncoder encoder(hs);


	return 0;
}
