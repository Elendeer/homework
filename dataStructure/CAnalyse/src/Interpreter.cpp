#include "../inc/Interpreter.hpp"


void Interpreter::advance() {
	++ m_idx;
}
TokenType Interpreter::peekType() const {
	return m_tokenlist[m_idx + 1].getType();
}

void Interpreter::multipleComment() {
	TokenType type = m_tokenlist[m_idx].getType();
	while (type != TokenType::COMMENT_END) {

		if (type == TokenType::NEWLINE) {
			++ m_lines;
			++ m_comment_lines;

			if (peekType() == TokenType::NEWLINE) {
				++ m_empty_lines;
			}

			advance();
		}
		else {
			advance();
		}
		type = m_tokenlist[m_idx].getType();
	}


	bool met_comment_start = false;
	for (int tmp = m_idx; m_tokenlist[tmp].getType() != TokenType::NEWLINE; ++ tmp) {
		if (m_tokenlist[tmp].getType() == TokenType::COMMENT_START) {
			met_comment_start = true;
			break;
		}
// 		else if (m_tokenlist[tmp].getType() == TokenType::END) {
// 			break;
// 		}
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
			multipleComment();
		}
		else {
			advance();
		}

		type = m_tokenlist[m_idx].getType();
	}

	// Skip )
	advance();
	type = m_tokenlist[m_idx].getType();

	// Find next type and skip NEWLINE.
	// Handel things like:
	// int main()
	// {
	// }
	while (type == TokenType::NEWLINE) {
		++ m_lines;

		// Handel things like:
		// int main()
		//
		// {
		// }
		if (m_idx && m_tokenlist[m_idx - 1].getType() == TokenType::NEWLINE) {
			++ m_empty_lines;
		}

		advance();
		type = m_tokenlist[m_idx].getType();
	}

	// It's just a declaration or macro if the type of next char is not {
	if (type != TokenType::LBRACE) {
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
				multipleComment();
			}
			else {
				advance();
			}

			type = m_tokenlist[m_idx].getType();
		}
	}

	++ m_functions;
}

char Interpreter::judgeFuncAver() {
	double aver = (double)m_lines / m_functions;

	if (aver >= 10 && aver <= 15) {
		return 'A';
	}
	else if ((aver >= 8 && aver <= 9)
			|| (aver >= 16 && aver <= 20)) {
		return 'B';
	}
	else if ((aver >= 5 && aver <= 7)
			|| (aver >= 21 && aver <= 24)) {
		return 'C';
	}
	else {
		return 'D';
	}
}
char Interpreter::judgeEmptyLines() {
	double rate = (double)m_empty_lines / m_lines;

	if (rate >= 0.15 && rate <= 0.25) {
		return 'A';
	}
	else if ((rate >= 0.1 && rate <= 0.14)
			|| (rate >= 0.26 && rate <= 0.3)) {
		return 'B';
	}
	else if ((rate >= 0.05 && rate <= 0.09)
			|| (rate >= 0.31 && rate <= 0.35)) {
		return 'C';
	}
	else {
		return 'D';
	}
}
char Interpreter::judgeCommentLines() {
	double rate = (double)m_comment_lines / m_lines;

	if (rate >= 0.15 && rate <= 0.25) {
		return 'A';
	}
	else if ((rate >= 0.1 && rate <= 0.14)
			|| (rate >= 0.26 && rate <= 0.3)) {
		return 'B';
	}
	else if ((rate >= 0.05 && rate <= 0.09)
			|| (rate >= 0.31 && rate <= 0.35)) {
		return 'C';
	}
	else {
		return 'D';
	}
}


Interpreter::Interpreter(Parser parser) :
	m_parser(parser), m_lines(0), m_empty_lines(0),
	m_comment_lines(0),m_functions(0) {

		m_tokenlist = m_parser.parse();
		m_idx = 0;
	}
Interpreter::~Interpreter() {}



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
			multipleComment();
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

	cout << "Total Lines : " << m_lines << endl;
	cout << "Total Functions : " << m_functions << endl;

	cout << "Style Assessment: " << endl;
	cout << "Average length of function : "
		<< (double)m_lines / m_functions
		<< "\t\tLevel : " << judgeFuncAver() << endl;

	cout << "Empty lines : " << m_empty_lines
		<< "\t\t\tLevel : " << judgeEmptyLines()<< endl;
	cout << "Comment lines : " << m_comment_lines
		<< "\t\tLevel : " << judgeCommentLines()<< endl;
}

