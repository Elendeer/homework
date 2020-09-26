#include "./../inc/LinkedList.hpp"
#include <iostream>

int main() {
	using namespace std;

	cout << "Note: The index of linked list start from 0." << endl;
	cout << endl;
	cout << "Create an empty list A:" << endl;
	LinkedList a;
	a.print();
	cout << "The size of list A: " << a.size() << endl;

	cout << "Over." << endl;
	cout << endl;

	cout << "Insert function test:" << endl;
	cout << "Insert nums one by one as per subscript increment:" << endl;
	a.insert(1);
	a.insert(2);
	a.insert(5);
	a.insert(10);
	a.insert(19);

	a.print();
	cout << "The size of list A: " << a.size() << endl;

	cout << "Insert 40 to A[3]:" << endl;
	a.insert(3, 40);

	a.print();
	cout << "The size of list A: " << a.size() << endl;
	cout << "Over." << endl;
	cout << endl;

	cout << "Delete function test:" << endl;
	cout << "Delete A[1]:" << endl;
	a.del(1);

	a.print();
	cout << "The size of list A: " << a.size() << endl;
	cout << "Over." << endl;
	cout << endl;

	cout << "Set function test:" << endl;
	cout << "Set A[3] = 4:" << endl;
	a.set(3, 4);

	a.print();
	cout << "Over." << endl;
	cout << endl;

	cout << "Search function test:" << endl;
	cout << "if 1 is in list : " << a.isInList(1) << endl;
	cout << "if 2 is in list : " << a.isInList(2) << endl;
	cout << "if 4 is in list : " << a.isInList(4) << endl;
	cout << "if -1 is in list : " << a.isInList(-1) << endl;

	cout << "Over." << endl;
	cout << endl;



	return 0;
}