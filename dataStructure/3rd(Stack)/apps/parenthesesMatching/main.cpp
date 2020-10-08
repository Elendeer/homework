#include <iostream>
#include "./../../../template/Stack.hpp"

int main() {
	using namespace std;

	Stack<char> s;
	char c;

	c = getchar();

	bool flag = true;

	while (c != '\n' && flag) {

		if (c == '(' || c == '[' || c == '{') {
			s.push(c);
		}
		else {
			switch (c) {
				case ')':
					while (!s.empty() && s.top() != '(') {
						s.pop();
					}
					if (s.empty()) {
						flag = false;
						break;
					}
					else {
						s.pop();
					}

					break;

				case ']':
					while (!s.empty() && s.top() != '[') {
						s.pop();
					}
					if (s.empty()) {
						flag = false;
						break;
					}
					else {
						s.pop();
					}

					break;
					
				case '}':
					while (!s.empty() && s.top() != '{') {
						s.pop();
					}
					if (s.empty()) {
						flag = false;
						break;
					}
					else {
						s.pop();
					}

					break;

				default:
					break;
			}
		}

		c = getchar();
	}

	if (!s.empty()) {
		flag = false;
	}

	if (flag) {
		cout << "Succeed" << endl;
	}
	else {
		cout << "Failed" << endl;
	}


	return 0;
}
