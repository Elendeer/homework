#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(NT)

#include <direct.h>
#define ADDRESS_BREAK '\\'


#elif __linux__

#include <unistd.h>
#define ADDRESS_BREAK '/'

#endif


#include <iostream>
#include <fstream>
#include <vector>

#include <cstring>


#include "../inc/Token.hpp"
#include "../inc/Lexer.hpp"
#include "../inc/Parser.hpp"
#include "../inc/Interpreter.hpp"

#include "../inc/AddressParser.hpp"

int main (int argc, char * argv[]) {
	using namespace std;

	AddressParser address_parser;

	string cwd_string = address_parser.getCwd();


	// ==================== Controling variables ====================

	bool test_mod = false;
	bool src_test_mod = false;
	bool token_test_mod = false;
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
			// TODO : show help message using AddressParser.
			cout << "Usage: ./main [options] [file]" << endl;

			cout << "Options:" << endl;
			cout << "-s, -src\t\tshow source codes program read." << endl;
			cout << "-token\t\t\tshow tokens lexer read from the source code." << endl;
			cout << "-t\t\t\ttesting mode, does exactly the same thing as using" << endl;
			cout << "-src -token." << endl;
			cout << "-h, -help\t\tshow this help message and exit." << endl;

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

	// ==================== Read source codes ====================

	string src;

	ifstream reader;
	reader.open(address_parser.parseRelativePath(src_file_string), ios::in);

	while (!reader.eof()) {
		// For reading bug in linux file.
		if (reader.peek() != (char)-1) {
			src += reader.get();
		}
		else {
			reader.ignore();
		}
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
