#include "../inc/Interpreter.hpp"

Interpreter::Interpreter(Parser parser) :
	m_parser(parser), m_lines(0), m_empty_lines(0),
	m_comment_lines(0),m_functions(0) {

		m_tokenlist = m_parser.parse();
		m_idx = 0;
	}


void Interpreter::advance() {
	++ m_idx;
}
TokenType Interpreter::peekType() const {
	return m_tokenlist[m_idx + 1].getType();
}

void Interpreter::multiple_comment() {
	TokenType type = m_tokenlist[m_idx].getType();
	while (type != TokenType::COMMENT_END) {

		if (type == TokenType::NEWLINE) {
			++ m_lines;
			++ m_comment_lines;
			advance();

			if (peekType() == TokenType::NEWLINE) {
				++ m_empty_lines;
			}
		}
		else {
			advance();
		}
		type = m_tokenlist[m_idx].getType();
	}

	// For NEWLINE after COMMENT_END.
	// ++ m_comment_lines;

	// TODO: Have a bug when meet COMMENT_END ANY* COMMENT_START 

	bool met_comment_start = false;
	for (int tmp = m_idx; m_tokenlist[tmp].getType() != TokenType::NEWLINE; ++ tmp) {
		if (m_tokenlist[tmp].getType() == TokenType::COMMENT_START) {
			met_comment_start = true;
			break;
		}
	}

	if (!met_comment_start) {
		++ m_comment_lines;
	}


	advance();
}

void Interpreter::function() {
	using std::cout;
	using std::endl;

	TokenType type = m_tokenlist[m_idx].getType();
	// Skip parameters in ()
	while (type != TokenType::RPAREN) {
		if (type == TokenType::NEWLINE) {
			++ m_lines;

			if (peekType() == TokenType::NEWLINE) {
				++ m_empty_lines;
			}

			advance();
		}
		else if (type == TokenType::COMMENT) {
			while (type != TokenType::NEWLINE) {
				advance();
				type = m_tokenlist[m_idx].getType();
			}
			++ m_comment_lines;
		}
		else if (type == TokenType::COMMENT_START) {
			advance();
			multiple_comment();
		}
		else {
			advance();
		}

		type = m_tokenlist[m_idx].getType();
	}

	// Skip )
	advance();
	type = m_tokenlist[m_idx].getType();

	// It's just a declaration if the type of next char is not {
	if (type == TokenType::ANY) {
		return;
	}
	else {
		while (type != TokenType::RBRACE) {
			if (type == TokenType::NEWLINE) {
				++ m_lines;

				if (peekType() == TokenType::NEWLINE) {
					++ m_empty_lines;
				}

				advance();
			}
			else if (type == TokenType::COMMENT) {
				while (type != TokenType::NEWLINE) {
					advance();
					type = m_tokenlist[m_idx].getType();
				}
				++ m_comment_lines;
			}
			else if (type == TokenType::COMMENT_START) {
				advance();
				multiple_comment();
			}
			else {
				advance();
			}

			type = m_tokenlist[m_idx].getType();
		}
	}

	++ m_functions;
}

void Interpreter::interprete() {
	using std::cout;
	using std::endl;

	TokenType type = m_tokenlist[m_idx].getType();

	// For empty lines in begin of the file.
	while (type == TokenType::NEWLINE) {
		++ m_lines;
		++ m_empty_lines;

		advance();
		type = m_tokenlist[m_idx].getType();
	}

	while (type != TokenType::END) {
		if (type == TokenType::NEWLINE) {
			++ m_lines;

			if (peekType() == TokenType::NEWLINE) {
				++ m_empty_lines;
			}

			advance();
		}
		else if (type == TokenType::COMMENT) {
			while (type != TokenType::NEWLINE) {
				advance();
				type = m_tokenlist[m_idx].getType();
			}
			++ m_comment_lines;
		}
		else if (type == TokenType::COMMENT_START) {
			advance();
			multiple_comment();
		}
		else if (type == TokenType::ANY) {
			if (peekType() == TokenType::ANY) {
				// Skip ANY
				advance();
				if (peekType() == TokenType::LPAREN) {
					// Skip ANY
					advance();
					// Skip (
					advance();

					function();
				}
			}
			else {
				advance();
			}
		}
		else {
			advance();
		}

		type = m_tokenlist[m_idx].getType();
	}
}

void Interpreter::printTokens() {
	using std::cout;
	using std::endl;

	for (auto i : m_tokenlist) {
		i.printType();

		if (i.getType() == TokenType::NEWLINE) {
			cout << endl;
		}
		else {
			cout << " ";
		}
	}
}

void Interpreter::printResult() {
	using std::cout;
	using std::endl;

	cout << "Lines : " << m_lines << endl;
	cout << "Empty lines : " << m_empty_lines << endl;
	cout << "Comment lines : " << m_comment_lines << endl;
	cout << "Function : " << m_functions << endl;
}

