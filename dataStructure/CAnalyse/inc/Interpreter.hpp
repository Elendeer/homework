#ifndef __INTERPRETER_HPP__
#define __INTERPRETER_HPP__

#include "./Parser.hpp"

class Interpreter {
private:
	Parser m_parser;
	int m_lines, m_empty_lines, m_comment_lines, m_functions;
	std::vector<Token> m_tokenlist;
	int m_idx;

	void advance();
	TokenType peekType() const;

	void multiple_comment();
	void function();
public:
	Interpreter(Parser parser);

	void interprete();
	void printTokens();
	void printResult();
};

#endif
