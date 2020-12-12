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
	v.push_back(m_current_token);

	return v;
}
