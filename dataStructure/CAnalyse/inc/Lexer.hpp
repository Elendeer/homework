#ifndef __LEXER_HPP__
#define __LEXER_HPP__

#include "./Token.hpp"
#include <iostream>

// Appointment: There is a NOCHAR in the end of string.
const char NOCHAR = (char)0;

class Lexer {
private :
	std::string m_text;
	int m_pos;

	char m_current_char;


	// Move the m_pos ahead and judge whether touch the end of m_text or not.
	void advance();

	// Skip the white space, which means m_pos += 1.
	void skipWhiteSpace();
	// Skip the tab, which means m_pos += 1.
	void skipTab();

	// Peek a char ahead, which means return m_text[m_pos + 1].
	char peek();

	// Read any words.
	void anyWord();

	// Read any string.
	void anyString();

public :
	Lexer(std::string text);
	~Lexer();

	// Return the next token of the text.
	Token getNextToken();
};

#endif
