#include <iostream>
#include "./Stack.hpp"

int main() {
	using namespace std;

	Stack<double> A = {1, 2.33, 99.54};
	A.print();

	A.pop();
	A.print();

	A.push(3.789);
	A.print();

	if (!A.pop()) {
		cout << "Pop failed" << endl;
	}
	A.print();
	cout << "size : " << A.size() << endl;

	if (!A.pop()) {
		cout << "Pop failed" << endl;
	}
	A.print();
	cout << "size : " << A.size() << endl;

	if (!A.pop()) {
		cout << "Pop failed" << endl;
	}
	A.print();
	cout << "size : " << A.size() << endl;
	
	if (!A.pop()) {
		cout << "Pop failed" << endl;
	}
	A.print();
	cout << "size : " << A.size() << endl;

	A.push(3.789);
	A.push(222.789);
	A.push(3.5);
	A.print();
	A.clear();
	A.print();

	return 0;
}
