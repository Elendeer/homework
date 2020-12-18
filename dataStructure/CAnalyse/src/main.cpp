#include <iostream>
#include <fstream>
#include <vector>

#include <cstring>

#include "../inc/Token.hpp"
#include "../inc/Lexer.hpp"
#include "../inc/Parser.hpp"
#include "../inc/Interpreter.hpp"

int main (int argc, char * argv[]) {
	using namespace std;

	// ==================== Controling variables ====================

	bool test_mod = false;
	bool src_test_mod = false;
	bool token_test_mod = false;

	for (int i = 1; i < argc; ++ i ) {
		if (strcmp(argv[i],"-t") == 0) {
			test_mod = true;
		}
		else if (strcmp(argv[i],"-src") == 0) {
			src_test_mod = true;
		}
		else if (strcmp(argv[i],"-token") == 0) {
			token_test_mod = true;
		}
		else {
			cout << "Invailid command line arguments!" << endl;
			exit(1);
		}
	}

	// ==================== Read source codes ====================

	string src;

	ifstream reader;
	reader.open("/home/daniel/CodeProject/homework/dataStructure/CAnalyse/test2.c", ios::in);

	while (!reader.eof()) {
		src += reader.get();
	}
	reader.close();

	// ==================== Build interpreter ====================

	Lexer lexer(src);
	Parser parser(lexer);
	Interpreter interpreter(parser);

	// ==================== Test mode outputs ====================

	if (test_mod) {
		cout << "========== Read source ==========" << endl;
		cout << src << endl;
		cout << "========== See tokens ==========" << endl;
		interpreter.printTokens();
		cout << endl;
		cout << "========== End of testing output ==========" << endl;
		cout << endl;
	}
	else {
		if (src_test_mod) {
			cout << "========== Read source ==========" << endl;
			cout << src << endl;
		}
		if (token_test_mod) {
			cout << "========== See tokens ==========" << endl;
			interpreter.printTokens();
			cout << endl;
		}
		if (src_test_mod || token_test_mod) {
			cout << "========== End of testing output ==========" << endl;
			cout << endl;
		}
	}

	// ==================== end of Test mode outputs ====================


	interpreter.interprete();
	interpreter.printResult();
	
	return 0;
}
