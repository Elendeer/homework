#include "../inc/Token.hpp"
#include <iostream>

Token::Token(TokenType type) : m_type(type) {
}

Token::~Token() {
}

TokenType Token::getType() const {
	return m_type;
}

void Token::printType() const {
	using std::cout;
	using std::endl;

	if (m_type == TokenType::NONE) {
		cout << "NONE" ;
	}
	else if (m_type == TokenType::ANY) {
		cout << "ANY" ;
	}
	else if (m_type == TokenType::NEWLINE) {
		cout << "NEWLINE" ;
	}
	else if (m_type == TokenType::COMMENT) {
		cout << "COMMENT" ;
	}
	else if (m_type == TokenType::COMMENT_START) {
		cout << "COMMENT_START" ;
	}
	else if (m_type == TokenType::COMMENT_END) {
		cout << "COMMENT_END" ;
	}
	else if (m_type == TokenType::LPAREN) {
		cout << "LPAREN" ;
	}
	else if (m_type == TokenType::RPAREN) {
		cout << "RPAREN" ;
	}
	else if (m_type == TokenType::LBRACE) {
		cout << "LBRACE" ;
	}
	else if (m_type == TokenType::RBRACE) {
		cout << "RBRACE" ;
	}
	else if (m_type == TokenType::END) {
		cout << "END" ;
	}
}
