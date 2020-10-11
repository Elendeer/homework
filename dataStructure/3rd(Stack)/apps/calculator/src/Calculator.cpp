#include <iostream>
#include "./../inc/Calculator.hpp"

Calculator::Calculator() {
}

Calculator::~Calculator() {
}



// Calculate a result from user's input.
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

			readOp();
			continue;
			// m_ops.push(m_current_char);
			// m_current_char = getchar();
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

	// for (auto i : m_nums) {
	// 	std::cout << i << " ";
	// }
	// std::cout << std::endl;
	// for (auto i : m_ops) {
	// 	std::cout << i << " ";
	// }
	// std::cout << std::endl;

	while (!m_ops.empty()) {
		useOp();
	}

	return m_nums.top();
}

// Read a number(double is fine).
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

void Calculator::useOp() {
	double a, b;
	char c = m_ops.top();
	switch (c) {
		case '+':
			a = m_nums.top();
			m_nums.pop();
			b = m_nums.top();
			m_nums.pop();

			m_ops.pop();
			m_nums.push(b + a);
			break;

		case '-':
			a = m_nums.top();
			m_nums.pop();
			b = m_nums.top();
			m_nums.pop();

			m_ops.pop();
			m_nums.push(b - a);
			break;

		case '*':
			a = m_nums.top();
			m_nums.pop();
			b = m_nums.top();
			m_nums.pop();

			m_ops.pop();
			m_nums.push(b * a);
			break;

		case '/':
			a = m_nums.top();
			m_nums.pop();
			b = m_nums.top();
			m_nums.pop();

			m_ops.pop();
			m_nums.push(b / a);
			break;

		default:
			break;
	}
}
