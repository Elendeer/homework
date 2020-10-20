#include <iostream>
#include "./../inc/Calculator.hpp"


int main() {
	using namespace std;
	Calculator A;

	cout << "=========================================================" << endl;
	cout << "+\tA very simple calculate wrote with stack.\t+" << endl;
	cout << "+\tYou can use '+', '-', '*', '/', '(', and ')\t+" << endl;
	cout << "+\tInput 'q' to quit.\t\t\t\t+" << endl;
	cout << "=========================================================" << endl;


	while (true) {
		cout << "> " ;
		try {
			double a = A.calculate();
			cout << ">> " << a << endl;
		}
		catch (int code){
			cout << "Read 'q', quit." << endl;
			break;
		}

	}

	return 0;
}
