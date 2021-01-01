#include "../inc/Analyzer.hpp"

#include <iostream>

int main (int argc, char * argv[]) {
	using namespace std;
	Analyzer analyzer;

	try {
		analyzer.readComArgs(argc, argv);
		analyzer.analyze();
	}
	catch (string info) {
		cout << info << endl;
	}

	return 0;
}
