/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-09-10 14:45:06
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-09-20 23:02:19
 * @Description  :
*********************************************/
#include <iostream>
#include "./../inc/Complex.hpp"

int main() {
	using namespace std;

	Complex a, b(2.4, 5);
	cout << "a :" << endl;
	a.show();
	cout << "b :" << endl;
	b.show();

	cout << endl << "Get function test:" << endl;
	cout << "Real part of b : " << b.getReal() << endl;
	cout << "Image part of b : " << b.getImage() << endl;
	cout << "Over." << endl;

	cout << endl;

	cout << "Set function test:" << endl;
	a.setReal(3.6);
	a.setImage(3);
	cout << "Real part of a : " << a.getReal() << endl;
	cout << "Image part of a : " << a.getImage() << endl;
	cout << "Over." << endl;

	cout << endl;

	cout << "Overload & cy-initial function test:" << endl;
	cout << "c = a + b" << endl << "c : " << endl;
	Complex c = a + b;
	c.show();
	cout << endl;
	cout << "c = a - b" << endl << "c : " << endl;
	c = a - b;
	c.show();
	cout << endl;
	cout << "c = a * b" << endl << "c : " << endl;
	c = a * b;
	c.show();
	cout << endl;
	cout << "c = a / b" << endl << "c : " << endl;
	c = a / b;
	c.show();
	cout << endl;
	cout << "Over." << endl;

	cout << endl;
	cout << "Now input two float numbers, as real/image part of 'a'." << endl;

	cin >> a;
	cout << "a :" << endl << a << endl;

	cout << a + b;


	return 0;
}
