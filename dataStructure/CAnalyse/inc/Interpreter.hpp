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

	char judge_lines();
	char judge_empty_lines();
	char judge_comment_lines();

public:
	Interpreter(Parser parser);
	~Interpreter();

	void interprete();
	void printTokens();
	void printResult();
};

#endif
