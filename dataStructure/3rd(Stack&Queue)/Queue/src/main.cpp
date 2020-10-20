#include <iostream>
#include "../inc/Queue.hpp"

int main() {
	using namespace std;

	Queue q;
	q.push(1);
	q.push(2);
	q.push(4);
	q.push(1);
	q.print();

	cout << "Size : " << q.size() << endl;

	cout << "Pop" << endl;

	q.pop();
	q.print();
	cout << "Size : " << q.size() << endl;

	cout << "Front : " << q.front() << endl;
	cout << "Back : " << q.back() << endl;


	cout << "Pop all" << endl;
	while (!q.empty()) {
		q.pop();
	}
	q.print();
	cout << "Size : " << q.size() << endl;


	return 0;
}
