#include <iostream>
#include "../inc/Parser.hpp"


void Parser::advance() {
	m_last_token = m_current_token;
	m_current_token = m_lexer.getNextToken();
}


Parser::Parser(Lexer lexer) : m_lexer(lexer) {
	m_current_token = m_lexer.getNextToken();
	// NONE type.
	m_last_token = Token();
}

Parser::~Parser() {}

void Parser::parse() {
	int c_comments = 0, c_lines = 0, c_empty = 0;
	TokenType type = m_current_token.getType();

	while (type != TokenType::END) {

		if (type == TokenType::ANY) {
			advance();
			type = m_current_token.getType();
		}

		else if (type == TokenType::COMMENT) {
			++ c_comments;

			advance();
			type = m_current_token.getType();
		}

		else if (type == TokenType::COMMENT_START) {
			while (type != TokenType::COMMENT_END) {
				if (type == TokenType::NEWLINE) {
					if (m_last_token.getType() == TokenType::NEWLINE) {
						++ c_empty;
					}

					++ c_comments;
					++ c_lines;
				}

				advance();
				type = m_current_token.getType();
			}
			++ c_comments;

			advance();
			type = m_current_token.getType();
		}

		else if (type == TokenType::NEWLINE) {
			if (m_last_token.getType() == TokenType::NEWLINE) {
				++ c_empty;
			}


			++ c_lines;
			advance();
			type = m_current_token.getType();
		}
	}

	using std::cout;
	using std::endl;

	cout << "lines: " << c_lines << endl;
	cout << "comments: " << c_comments << endl;
	cout << "empty lines: " << c_empty << endl;
}
