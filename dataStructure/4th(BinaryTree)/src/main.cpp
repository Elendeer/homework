#include <iostream>
#include "../inc/BinaryTree.hpp"


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



	return 0;
}
