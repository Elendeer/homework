#include <iostream>
#include "./../inc/Calculator.hpp"

Calculator::Calculator() {
}

Calculator::~Calculator() {
}



// Calculate a result from user's input.
// Throw a exception(int 0) when receive a 'q'.
double Calculator::calculate() {
	m_current_char = getchar();

	while (m_current_char != '\n') {
		if (m_current_char >= '0' && m_current_char <= '9') {
			// You can always get a new char after readNum function.
			readNum();
			continue;
		}

		if (m_current_char == '+' || m_current_char == '-'
				|| m_current_char == '*' || m_current_char == '/'
				|| m_current_char == '(' || m_current_char == ')') {

			try {
				readOp();
			}
			catch (int error_code) {
				if (error_code == -1) {
					std::cout << "Invaild syntax. Expected more operands."
						<< std::endl;
					this -> clean();
				}
				else if (error_code == -2) {
					std::cout << "Invaild syntax. Expected paired parentheses."
						<< std::endl;
					this -> clean();
				}

				break;
			}

			continue;
		}

		// 'q' for quit.
		if (m_current_char == 'q') {
			throw 0;
		}

		// Skip the space.
		if (m_current_char == ' ') {
			m_current_char = getchar();
		}
	}


	while (!m_ops.empty()) {
		try {
			useOp();
		}
		catch (int error_code) {
			if (error_code == -1) {
				std::cout << "Invaild syntax. Expected more operands."
					<< std::endl;
				this -> clean();
			}
			else if (error_code == -2) {
				std::cout << "Invaild syntax. Expected paired parentheses."
					<< std::endl;
				this -> clean();
			}

			break;
		}
	}

	return m_nums.top();
}


// Read a number(double is fine).
// It will not return false in fact.
bool Calculator::readNum() {
	double num = (double)(m_current_char - '0');

	m_current_char = getchar();
	while ((m_current_char >= '0' && m_current_char <= '9') || m_current_char == '.') {
		if (m_current_char != '.') {
			// Count it in.
			num = num * 10 + (m_current_char - '0');
			// Get next.
			m_current_char = getchar();
		}
		else {
			// Skip the decimal point and read the numbers of
			// decimal part.
			m_current_char = getchar();

			int count = 1;

			while (m_current_char >= '0' && m_current_char <= '9') {
				num = num + (double)(m_current_char - '0') / (10 * count);
				count ++;
				m_current_char = getchar();
			}
		}
	}

	return m_nums.push(num);
}

// Read a operator from the input.
// It will not return false in fact.
// But it will try to ues a operator when some specific circumstances,
// so it may throw a exception.
bool Calculator::readOp() {
	if (m_ops.empty() || m_ops.top() == '(') {
		m_ops.push(m_current_char);
		m_current_char = getchar();
	}
	else {
		char c;
		double a, b;

		if (m_current_char == '+' || m_current_char == '-') {
			c = m_ops.top();
			switch (c) {
				case '+':
				case '-':
				case '*':
				case '/':
					useOp();
					break;

				default:
					break;
			}
			m_ops.push(m_current_char);

			m_current_char = getchar();

		}
		else if (m_current_char == '*' || m_current_char == '/') {
			c = m_ops.top();
			switch (c) {
				case '*':
				case '/':
					useOp();
					break;

				default:
					break;
			}


			m_ops.push(m_current_char);

			m_current_char = getchar();
		}
		else if (m_current_char == '(') {
			m_ops.push(m_current_char);
			m_current_char = getchar();
		}
		else { // ')'
			c = m_ops.top();
			while (c != '(') {
				useOp();
				c = m_ops.top();
			}
			m_ops.pop();

			m_current_char = getchar();
		}
	}

	return true;
}

// Ues a operator in the stack, which means pop it and do calculate.
// Throw exception if there is any mistack when using a operator.
void Calculator::useOp() {
	double a, b;
	char c = m_ops.top();
	switch (c) {
		case '+':
			if (!(a = m_nums.top())) {
				throw -1;
			}
			m_nums.pop();
			if (!(b = m_nums.top())) {
				throw -1;
			}
			m_nums.pop();

			m_ops.pop();
			m_nums.push(b + a);
			break;

		case '-':
			if (!(a = m_nums.top())) {
				throw -1;
			}
			m_nums.pop();
			if (!(b = m_nums.top())) {
				throw -1;
			}
			m_nums.pop();

			m_ops.pop();
			m_nums.push(b - a);
			break;

		case '*':
			if (!(a = m_nums.top())) {
				throw -1;
			}
			m_nums.pop();
			if (!(b = m_nums.top())) {
				throw -1;
			}
			m_nums.pop();

			m_ops.pop();
			m_nums.push(b * a);
			break;

		case '/':
			if (!(a = m_nums.top())) {
				throw -1;
			}
			m_nums.pop();
			if (!(b = m_nums.top())) {
				throw -1;
			}
			m_nums.pop();

			m_ops.pop();
			m_nums.push(b / a);
			break;

		default:
			throw -2;
			break;
	}
}

// Clean up tow stacks of calculator.
void Calculator::clean() {
	m_nums.clean();
	m_ops.clean();
}
