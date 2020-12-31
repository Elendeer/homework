#include <iostream>
#include <fstream>
#include <vector>

#include <cstring>


#include "../inc/Token.hpp"
#include "../inc/Lexer.hpp"
#include "../inc/Parser.hpp"
#include "../inc/Interpreter.hpp"

#include "../inc/FileReader.hpp"

int main (int argc, char * argv[]) {
	using namespace std;

	FileReader file_reader;
	// ==================== Controling variables ====================

	bool test_mod = false;
	bool src_test_mod = false;
	bool token_test_mod = false;
	// bool dir_mode = false;
	string src_file_string;

	for (int i = 1; i < argc; ++ i ) {
		if (strcmp(argv[i],"-t") == 0) {
			test_mod = true;
		}
		else if (strcmp(argv[i],"-src") == 0 || strcmp(argv[i],"-s") == 0) {
			src_test_mod = true;
		}
		else if (strcmp(argv[i],"-token") == 0) {
			token_test_mod = true;
		}
		else if (*(argv[i] + strlen(argv[i]) - 2) == '.'
				&& *(argv[i] + strlen(argv[i]) - 1) == 'c') {

			src_file_string = argv[i];
			cout << "Input file : " << src_file_string << endl;
		}
		else if (strcmp(argv[i], "-help") == 0 || strcmp(argv[i], "-h") == 0) {
			cout << file_reader.readHelp() << endl;
			return 0;
		}
		else if (strcmp(argv[i], "-path") == 0 || strcmp(argv[i], "-p") == 0) {
			file_reader.printDir();
			cout << "========== ========== ==========" << endl;
		}
		else if (file_reader.isDir(argv[i])) {
			cout << "Your input is a dir" << endl;
			// dir_mode = true;
			return 0;
		}
		else {
			cout << "Invailid command line arguments!" << endl;
			exit(1);
		}
	}

	if (src_file_string.empty()) {
		cout << "Whithout input file!" << endl;
		exit(1);
	}


	// ==================== Build interpreter ====================

	string src;

	try {
		src = file_reader.readFile(src_file_string);
	}
	catch (string info) {
		cout << info << endl;
		exit(1);
	}

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
