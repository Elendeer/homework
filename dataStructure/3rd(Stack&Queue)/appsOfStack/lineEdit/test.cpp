/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-10-13 13:00:24
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-10-31 21:00:00
 * @Description  :
*********************************************/

#include <iostream>
#include "./../../../template/Stack.hpp"


int main() {
	using namespace std;

	char c;
	Stack<char> s;

	c = getchar();

	while (c != EOF) {

		switch (c) {
			case '#':
				s.pop();
				break;

			case '@':
                while (!s.empty() && s.top() != '\n') {
                    s.pop();
                }
				break;

			default:
				s.push(c);
				break;
		}

		c = getchar();
	}

    for (auto item : s) {
        cout << item;
    }
    cout << endl;

	// cout << "Stack : " << endl;
	// s.print();




	return 0;
}
