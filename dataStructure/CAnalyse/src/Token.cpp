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
		cout << "NONE" << endl;
	}
	else if (m_type == TokenType::ANY) {
		cout << "ANY" << endl;
	}
	else if (m_type == TokenType::NEWLINE) {
		cout << "NEWLINE" << endl;
	}
	else if (m_type == TokenType::COMMENT) {
		cout << "COMMENT" << endl;
	}
	else if (m_type == TokenType::COMMENT_START) {
		cout << "COMMENT_START" << endl;
	}
	else if (m_type == TokenType::COMMENT_END) {
		cout << "COMMENT_END" << endl;
	}
	else if (m_type == TokenType::END) {
		cout << "END" << endl;
	}
}
