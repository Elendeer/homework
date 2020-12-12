#include <iostream>
#include <fstream>
#include <vector>

#include "../inc/Token.hpp"
#include "../inc/Lexer.hpp"
#include "../inc/Parser.hpp"
#include "../inc/Interpreter.hpp"

int main () {
	using namespace std;

	string src;

	ifstream reader;
	reader.open("/home/daniel/CodeProject/homework/dataStructure/CAnalyse/test2.c", ios::in);

	while (!reader.eof()) {
		src += reader.get();
	}
	cout << src << endl;
	cout << "============" << endl;

	reader.close();

	Lexer lexer(src);
	Parser parser(lexer);
	Interpreter interpreter(parser);

	interpreter.printTokens();
	cout << endl;
	interpreter.interprete();
	cout << endl;
	interpreter.printResult();
	
	return 0;
}
