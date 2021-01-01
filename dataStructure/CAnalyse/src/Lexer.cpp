#include "../inc/Lexer.hpp"

/***** Private functions *****/

void Lexer::advance() {
	++ m_pos;
	if (m_pos > (int)m_text.size() - 1) {
		m_current_char = NOCHAR;
	}
	else {
		m_current_char = m_text[m_pos];
	}
}

void Lexer::skipWhiteSpace() {
	advance();
}

void Lexer::skipTab() {
	advance();
}

char Lexer::peek() {
	return m_text[m_pos + 1];
}

void Lexer::anyWord() {
	while (m_current_char != ' ' && m_current_char != NOCHAR
			&& m_current_char != '\n'

			&& (m_current_char != '/' || peek() != '*')
			&& (m_current_char != '/' || peek() != '/')
			&& (m_current_char != '*' || peek() != '/')

			&& (m_current_char != '\"' || m_in_comment || m_in_multi_comment)
			&& (m_current_char != '\'' || m_in_comment || m_in_multi_comment)

			&& (m_current_char != '(' || m_in_comment || m_in_multi_comment)
			&& (m_current_char != ')' || m_in_comment || m_in_multi_comment)
			&& (m_current_char != '{' || m_in_comment || m_in_multi_comment)
			&& (m_current_char != '}' || m_in_comment || m_in_multi_comment)) {
		advance();
	}
}

void Lexer::anyString() {
	// Skip the first '\"'.
	advance();
	while (m_current_char != '\"') {
		// for escape character back slash.
		if (m_current_char == '\\') {
			advance();
		}
		advance();
	}
	// Skip the last '\"'.
	advance();
}

void Lexer::anyChar() {
	// Skip the first '\''.
	advance();
	while (m_current_char != '\'') {
		// for escape character back slash.
		if (m_current_char == '\\') {
			advance();
		}
		advance();
	}
	// Skip the last '\''.
	advance();
}


/***** Public functions *****/

Lexer::Lexer(std::string text) : m_text(text), m_pos(0) {
	m_current_char = m_text[m_pos];
	m_in_comment = false;
	m_in_multi_comment = false;
}

Lexer::~Lexer() {}


Token Lexer::getNextToken() {
	while (m_current_char != NOCHAR) {
		if (m_current_char == ' ') {
			skipWhiteSpace();
		}
		else if (m_current_char == '\t') {
			skipTab();
		}
		else if (m_current_char == '\n') {
			advance();

			m_in_comment = false;
			return Token(TokenType::NEWLINE);
		}
		else if (m_current_char == '/' && peek() == '/') {
			advance();
			advance();
			m_in_comment = true;
			return Token(TokenType::COMMENT);
		}
		else if (m_current_char == '/' && peek() == '*') {
			advance();
			advance();
			m_in_multi_comment = true;
			return Token(TokenType::COMMENT_START);
		}
		else if (m_current_char == '*' && peek() == '/') {
			advance();
			advance();
			m_in_multi_comment = false;
			return Token(TokenType::COMMENT_END);
		}
		else if (m_current_char == '('
		&& !m_in_comment && !m_in_multi_comment) {
			advance();
			return Token(TokenType::LPAREN);
		}
		else if (m_current_char == ')'
		&& !m_in_comment && !m_in_multi_comment) {
			advance();
			return Token(TokenType::RPAREN);
		}
		else if (m_current_char == '{'
		&& !m_in_comment && !m_in_multi_comment) {
			advance();
			return Token(TokenType::LBRACE);
		}
		else if (m_current_char == '}'
		&& !m_in_comment && !m_in_multi_comment) {
			advance();
			return Token(TokenType::RBRACE);
		}
		else if (m_current_char == '"'
		&& !m_in_comment && !m_in_multi_comment) {
			anyString();
			return Token(TokenType::ANY);
		}
		else if (m_current_char == '\''
		&& !m_in_comment && !m_in_multi_comment) {
			anyChar();
			return Token(TokenType::ANY);
		}
		else {
			anyWord();
			return Token(TokenType::ANY);
		}
	}

	return Token(TokenType::END);
}
