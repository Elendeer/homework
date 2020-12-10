#include <iostream>
#include <fstream>

#include "../inc/Token.hpp"
#include "../inc/Lexer.hpp"
#include "../inc/Parser.hpp"

int main () {
	using namespace std;

	string src;

	ifstream reader;
	reader.open("/home/daniel/CodeProject/homework/dataStructure/CAnalyse/test.c", ios::in);

	while (!reader.eof()) {
		src += reader.get();
	}
	cout << src << endl;
	cout << "============" << endl;

	reader.close();

	Lexer lexer(src);
	// Token token;
	// token = lexer.getNextToken();

	// while (token.getType() != TokenType::END) {
	// 	token.printType();
	// 	token = lexer.getNextToken();
	// }
	// token.printType();
	

	Parser parser(lexer);
	parser.parse();

	return 0;
}
