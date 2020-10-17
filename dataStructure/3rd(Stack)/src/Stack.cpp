/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-10-10 09:37:07
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-10-13 13:01:19
 * @Description  :
*********************************************/

#include "./../inc/Stack.hpp"

#include <iostream>

Stack::Stack() : m_top(0){
	if (!(m_stack = new int [101])) {
		std::cout << "Memory error" << std::endl;
	}
}

Stack::Stack(std::initializer_list<int> list) : m_top(0) {
	int len = 100;
	if (list.size() >= 100) {
		len = 1;
		int tmp = list.size();
		while (tmp) {
			tmp /= 10;
			len *= 10;
		}
	}
	if (!(m_stack = new int [len + 1])) {
		std::cout << "Memory error" << std::endl;
	}

	for (auto item : list) {
		this -> push(item);
	}
}

Stack::Stack(int len) : m_top(0) {
	if (!(m_stack = new int [len + 1])) {
		std::cout << "Memory error" << std:: endl;
	}
}

Stack::~Stack() {
	delete [] m_stack;
	std::cout << "Done." << std::endl;
}

/***** Basic operations *****/

bool Stack::push(int data) {
	if (m_top == 100) {
		std::cout << "Out of range!" << std::endl;
		return false;
	}

	m_stack[++ m_top] = data;
	return true;
}

bool Stack::pop() {
	if (!m_top) {
		return false;
	}

	m_top --;

	return true;
}

void Stack::clean() {
	m_top = 0;
}

/***** Get things *****/

bool Stack::empty() const {
	if (m_top == 0) return true;
	return false;
}

int Stack::top() const {
	if (m_top == 0) {
		std::cout << "Stack is empty" << std::endl;
		return 0;
	}

	return m_stack[m_top];
}

int Stack::size() {
	return m_top;
}


void Stack::print() {
	std::cout << "[";
	for (int i = 1; i < m_top; ++ i) {
		std::cout << m_stack[i] << ", ";
	}
	if (m_top != 0) std::cout << m_stack[m_top];
	std::cout << "]" << std::endl;
}
