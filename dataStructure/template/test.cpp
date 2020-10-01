#include "./LinkedList.hpp"
#include <iostream>

int main() {
	using namespace std;

	cout << "Note: The index of linked list start from 0." << endl;
	cout << endl;
	cout << "Create an empty list A:" << endl;
	SingleLinkedList<int> A;
	A.print();
	cout << "The size of list A: " << A.size() << endl;

	cout << "Over." << endl;
	cout << endl;

	cout << "Insert function test:" << endl;
	cout << "Insert nums one by one as per subscript increment:" << endl;
	A.insert(1);
	A.insert(2);
	A.insert(5);
	A.insert(10);
	A.insert(19);

	A.print();
	cout << "The size of list A: " << A.size() << endl;

	cout << "Insert 40 to A[3]:" << endl;
	A.insert(3, 40);

	A.print();
	cout << "The size of list A: " << A.size() << endl;
	cout << "Over." << endl;
	cout << endl;

	cout << "Delete function test:" << endl;
	cout << "Delete A[1]:" << endl;
	A.del(1);

	A.print();
	cout << "The size of list A: " << A.size() << endl;
	cout << "Over." << endl;
	cout << endl;

	cout << "Set function test:" << endl;
	cout << "Set A[3] = 4:" << endl;
	A.set(3, 4);

	A.print();
	cout << "Over." << endl;
	cout << endl;

	cout << "Search function test:" << endl;
	cout << "if 1 is in list : " << A.isInList(1) << endl;
	cout << "if 2 is in list : " << A.isInList(2) << endl;
	cout << "if 4 is in list : " << A.isInList(4) << endl;
	cout << "if -1 is in list : " << A.isInList(-1) << endl;

	cout << "Over." << endl;
	cout << endl;

	cout << "Init objects with initializer list:" << endl;
	SingleLinkedList<int> B = {3, 2, 1}, C = {11, 3, 0, -3};
	B.print();
	C.print();

	cout << "Merge function test:" << endl;
	B.merge(C);
	B.print();
	cout << B.size() << endl;

	cout << endl;
	cout << "Access nodes by[] test:" << endl;
	cout << "B[0] : " << B[0] << endl;
	cout << "B[1] : " << B[1] << endl;
	cout << "B[2] : " << B[2] << endl;
	cout << "B[5] : " << B[5] << endl;
	cout << "B[123] : " << B[123] << endl;

	cout << "Over." << endl;
	cout << endl;




	return 0;
}
