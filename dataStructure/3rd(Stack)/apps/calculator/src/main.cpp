#include <iostream>
#include "./../inc/Calculator.hpp"


int main() {
	using namespace std;
	Calculator A;

	cout << "A very simple calculate wrote with stack." << endl;
	cout << "You can use '+', '-', '*', '/', '(', and ')" << endl;
	cout << "Input 'q' to quit." << endl;


	while (true) {
		cout << "> " ;
		try {
			double a = A.calculate();
			cout << ">> " << a << endl;
		}
		catch (int){
			break;
		}

	}

	return 0;
}
