#include "./../../../../template/Stack.hpp"


class Calculator {
private:
	Stack<double> m_nums;
	Stack<char> m_ops;

	char m_current_char;

	// Read a number(double is fine).
	bool readNum();
	bool readOp();

	// Ues a operator in the stack, pop it and do calculate.
	void useOp();

public:
	Calculator();
	~Calculator();

	// Calculate a result from user's input.
	double calculate();
};

