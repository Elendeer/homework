#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(NT)

#define OS 0

#elif __linux__

#define OS 1

#endif

#include <iostream>
#include "../inc/Parser.hpp"


void Parser::advance() {
	m_current_token = m_lexer.getNextToken();
}


Parser::Parser(Lexer lexer) : m_lexer(lexer) {
	m_current_token = m_lexer.getNextToken();
}

Parser::~Parser() {}

std::vector<Token> Parser::parse() {
	std::vector<Token> v;

	while (m_current_token.getType() != TokenType::END) {
		v.push_back(m_current_token);
		m_current_token = m_lexer.getNextToken();
	}

	// Windows will not add a newline after end of file.
	if (!v.empty() && OS == 0) {
		v.push_back(Token(TokenType::NEWLINE));
	}

	v.push_back(m_current_token);

	return v;
}
