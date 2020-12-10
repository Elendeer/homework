#ifndef __TOKEN_HPP__
#define __TOKEN_HPP__

enum class TokenType {
	NONE,

	ANY,
	NEWLINE,
	COMMENT,
	COMMENT_START,
	COMMENT_END,
	END
};

class Token {
private :
	TokenType m_type;

public :
	Token(TokenType type = TokenType::NONE);
	
	~Token();

	// Return the type of the token.
	TokenType getType() const;

	// Print the string representation of the type of the token.
	void printType() const;
};

#endif
