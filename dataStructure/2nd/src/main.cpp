/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-09-15 13:14:03
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-09-15 13:22:14
 * @Description  :
*********************************************/
#include <iostream>
#include "./../inc/LinearList.hpp"

int main() {
	using namespace std;

	LinearList a;

	cout << "Insert function test:" << endl;
	a.insert(1);
	a.insert(2);
	a.insert(3);

	a.print();
	cout << "Size: " << a.size() << endl;
	cout << "Over" << endl;
	cout << endl;


	cout << "Del function test:" << endl;
	a.del(2);

	a.print();
	cout << "Size: " << a.size() << endl;
	cout << "Over" << endl;


	cout << "Set function test:" << endl;
	a.set(100, 1);

	a.print();
	cout << "Size: " << a.size() << endl;
	cout << "Over" << endl;
	cout << endl;


	int num = -1;
	cout << "Let num = -1" << endl;

	cout << "Get function test: to get a num from the list:" << endl;
	cout << "Get a[3]:" << endl;
	num = a.getNum(3);
	cout << "num = " << num << endl;
	cout << "Get a[2]:" << endl;
	num = a.getNum(2);
	cout << "num = " << num << endl;

	cout << "Over" << endl;
	cout << endl;

	cout << "Search function test:" << endl;
	cout << "Enter a num: ";
	cin >> num;
	cout << "Search for " << num << " in a:" << endl;
	if (a.search(num)) {
		cout << "Found number 1 in index " << a.search(num) << endl;
	}
	else {
		cout << "No found" << endl;
	}
	cout << "Over" << endl;
	cout << endl;

	cout << "Merge function test:" << endl;
	cout << "List A:" << endl;
	a.print();
	cout << "Set list B:" << endl;
	LinearList b;
	b.insert(789);
	b.insert(456);
	b.insert(23);
	b.insert(1);
	b.print();

	LinearList c = LinearList::merge(a, b);
	cout << "Merge a and b :" << endl;
	c.print();
	cout << "Over." << endl;

	
	


	return 0;
}
