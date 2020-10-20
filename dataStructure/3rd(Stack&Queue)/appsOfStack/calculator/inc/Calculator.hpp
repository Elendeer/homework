#include "./../../../../template/Stack.hpp"


class Calculator {
private:
	Stack<double> m_nums;
	Stack<char> m_ops;

	char m_current_char;

	// Read a number(double is fine).
	// It will not return false in fact.
	bool readNum();

	// Read a operator from the input.
	// It will not return false in fact.
	// But it will try to ues a operator when some specific circumstances,
	// so it may throw a exception.
	bool readOp();

	// Ues a operator in the stack, which means pop it and do calculate.
	// Throw exception if there is any mistack when using a operator.
	void useOp();

	// Clean up tow stacks of calculator.
	void clean();

public:
	Calculator();
	~Calculator();

	// Calculate a result from user's input.
	// Throw a exception(int 0) when receive a 'q'.
	double calculate();
};

