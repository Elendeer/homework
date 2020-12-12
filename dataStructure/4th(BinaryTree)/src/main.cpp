/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-11-26 14:43:45
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-12-12 18:40:22
 * @Description  :
*********************************************/

#include <iostream>
#include "../inc/BinaryTree.hpp"
#include "../inc/Huffman.hpp"


int main() {
	using namespace std;

	string s = "123nn3n4nn345nn6nnnn";
	BinaryTree t(s);

	cout << "Preorder Traversed: ";
	t.printDLR();
	cout << "Inorder Traversed: ";
	t.printLDR();
	cout << "Postorder Traversed: ";
	t.printLRD();

	cout << "Depth: " << t.getDepth() << endl;
	cout << "Leaves: " << t.getLeavesNum() << endl;
	cout << "Nodes: " << t.getNodesNum() << endl;

	cout << "Visualization:" << endl;
	t.draw();

	cout << "HuffmanEncoder test:" << endl;
	cout << "Input String : \"abbccdddd\"" << endl;
	HuffmanEncoder encoder("abbcccdddd");
	encoder.encode();


	return 0;
}
