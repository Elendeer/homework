#ifndef __PARSER_HPP__
#define __PARSER_HPP__

#include "Lexer.hpp"
#include <vector>

class Parser {
private :
	Lexer m_lexer;
	Token m_current_token;

	// m_last_token = m_current_token;
	// m_current_token = m_lexer.getNextToken();
	void advance();

public :
	Parser(Lexer lexer);
	~Parser();

	std::vector<Token> parse();
};


#endif
