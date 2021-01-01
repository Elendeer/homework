#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*********************************************
* enum types, reflections & constants
*********************************************/

// Enum type to record the type of a token.
enum class TokenType {
    NONE,

    // Reserved keywords
    BEGIN,
    END,
    PROGRAM,
    VAR,

    // Types, which are also reserved keywords.
    INTEGER,
    REAL,

    // Values
    INTEGER_CONST,
    REAL_CONST,

    MUL,
    INTEGER_DIV, // the DIV reserved keyword
    FLOAT_DIV,
    PLUS,
    MINUS,
    LPAREN,
    RPAREN,

    eEOF,

    DOT,
    ASSIGN,
    SEMI,
    COMMA,
    ID,

    COLON,
};

// String representation of TokenTypes.
const std::string TokenTypeString[] = {
    "NONE",

    // Reserved keywords
    "BEGIN",
    "END",
    "PROGRAM",
    "VAR",

    // Types, which are also reserved keywords.
    "INTEGER",
    "REAL",

    // Values
    "INTEGER_CONST",
    "REAL_CONST",

    "MUL",
    "INTEGER_DIV", // the DIV reserved keyword
    "FLOAT_DIV",
    "PLUS",
    "MINUS",
    "LPAREN",
    "RPAREN",

    "eEOF",

    "DOT",
    "ASSIGN",
    "SEMI",
    "COMMA",
    "ID",

    "COLON",
};

const char NOCHAR = '#';
const int NOVAL = -1;

/*********************************************
* classes & functions
*********************************************/

// The type of value of each token may be different,
// And each token have noly one value.
// So we put pointers of different types into this union.
union TokenValue {
	void * p;
    int * p_int;
    string * p_str;
    double * p_double;
};

// convert a interger to a string representation
string repr(int num);

class Token {
private:
    TokenType m_type;

    // TODO: Consider using union and refactor some functions.
    // int m_value;

    // string m_strVal;

    TokenValue m_value;


public:
    Token();
    Token(TokenType type, int value);
    Token(TokenType type, double value);
    Token(TokenType type, const string & value);
    Token(const Token &obj) = default;

    // String representation of the class instance.
    // Examples:
    // Token(INTEGER, 3)
    // Token(MUL, '+')
    void str_repr();

    TokenType getType() const;
    void * getVal() const;

    ~Token();
};



/*********************************************
*********************************************/


string repr(int num) {
    string s;
    while (num != 0) {
        int n = num % 10;
        num /= 10;
        s = (char)(n + '0') + s;
    }
    return s;
}

/*********************************************
* Overload the construction function to fit different
* input value (int / string).
*********************************************/

// Appointment: None type token have int value 0 by default.
Token::Token() : m_type(TokenType::NONE) {
    m_value.p_str = new string("NONE");
}

Token::Token(TokenType type, int value) : m_type(type) {
    m_value.p_int = new int(value);
}
Token::Token(TokenType type, double value) : m_type(type) {
	m_value.p_double = new double (value);
}
Token::Token(TokenType type, const string &value) : m_type(type) {
    m_value.p_str = new string(value);
}

void Token::str_repr() {
    string type = TokenTypeString[(int)m_type];
	if (m_type == TokenType::INTEGER_CONST) {
		cout << "Token(" + type + ", " <<
		*m_value.p_int << ")";
	}
	else if (m_type == TokenType::REAL_CONST) {
		cout << "Token(" + type + ", " <<
		*m_value.p_double << ")";
	}
	else {
		cout << "Token(" + type + ", " <<
		*m_value.p_str << ")";
	}
}

TokenType Token::getType() const {
    return m_type;
}

void * Token::getVal() const {
	return m_value.p;
}

Token::~Token() {
    if (m_type == TokenType::INTEGER_CONST) {
        delete m_value.p_int;
    }
    else if (m_type == TokenType::REAL_CONST) {
        delete m_value.p_double;
    }
    else {
        delete m_value.p_str;
    }
}


int main ()  {
	cout << sizeof(int*) << endl;
	cout << sizeof(char*) << endl;
	cout << sizeof(string*) << endl;
	cout << sizeof(vector<string>*) << endl;
	cout << sizeof(double(*)()) << endl;

	Token a;

	a.str_repr();
	cout << endl;
	cout << *(string*)a.getVal() << endl;

	Token b(TokenType::REAL_CONST, 12.35);

	b.str_repr();
	cout << endl;
	cout << *(double*)b.getVal() << endl;

	Token c(TokenType::INTEGER_CONST, 129);
	c.str_repr();
	cout << endl;
	cout << *(int*)c.getVal() << endl;

	return 0;
}
