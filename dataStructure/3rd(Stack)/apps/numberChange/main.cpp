#include <iostream>
#include "../../../template/Stack.hpp"

int main() {
	using namespace std;

	int num;
	cout << "Enter a integer, put it in octal number system." << endl;
	cin >> num;

	Stack<int> s;
	while (num) {
		s.push(num % 8);
		num /= 8;
	}

	cout << "output: ";
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	


	return 0;
}
