#include <iostream>
#include "./../inc/Stack.hpp"

int main() {
	using namespace std;

	cout << "Create a stack A = {1, 3, 4} :" << endl;
	Stack A = {1, 3, 4};
	A.print();

	cout << "Top of A: " << A.top() << endl;

	cout << "After pop :";
	A.pop();
	A.print();
	

	return 0;
}
