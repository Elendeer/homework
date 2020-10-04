#ifndef _STACK_HPP_
#define _STACK_HPP_

#include <iostream>

/***** Declaration *****/

template <typename T>
class Stack {
private:
	T* m_stack;
	int m_top;
public:
	Stack();
	Stack(std::initializer_list<T> list);
	Stack(int len);
	~Stack();

	// Basic operations.

	bool push(T data);
	bool pop();
	void clear();

	
	// Get things.

	bool empty() const;
	int top() const;
	int size();

	void print();
};


/***** Definition *****/


template <typename T>
Stack<T>::Stack() : m_top(0){
	if (!(m_stack = new T [101])) {
		std::cout << "Memory error" << std::endl;
	}
}

template <typename T>
Stack<T>::Stack(std::initializer_list<T> list) : m_top(0) {
	int len = 100;
	if (list.size() >= 100) {
		len = 1;
		int tmp = list.size();
		while (tmp) {
			tmp /= 10;
			len *= 10;
		}
	}
	if (!(m_stack = new T [len + 1])) {
		std::cout << "Memory error" << std::endl;
	}

	for (auto item : list) {
		this -> push(item);
	}
}

template <typename T>
Stack<T>::Stack(int len) : m_top(0) {
	if (!(m_stack = new T [len + 1])) {
		std::cout << "Memory error" << std:: endl;
	}
}

template <typename T>
Stack<T>::~Stack() {
	delete [] m_stack;
	std::cout << "Done." << std::endl;
}

/***** Basic operations *****/

template <typename T>
bool Stack<T>::push(T data) {
	if (m_top == 100) {
		std::cout << "Out of range!" << std::endl;
		return false;
	}

	m_stack[++ m_top] = data;
	return true;
}

template <typename T>
bool Stack<T>::pop() {
	if (!m_top) {
		return false;
	}

	m_top --;

	return true;
}

template <typename T>
void Stack<T>::clear() {
	m_top = 0;
}

/***** Get things *****/

template <typename T>
bool Stack<T>::empty() const {
	if (m_top == 0) return true;
	return false;
}

template <typename T>
int Stack<T>::top() const {
	if (m_top == 0) {
		std::cout << "Stack is empty" << std::endl;
		return 0;
	}

	return m_stack[m_top];
}

template <typename T>
int Stack<T>::size() {
	return m_top;
}


template <typename T>
void Stack<T>::print() {
	std::cout << "[";
	for (int i = 1; i < m_top; ++ i) {
		std::cout << m_stack[i] << ", ";
	}
	if (m_top != 0) std::cout << m_stack[m_top];
	std::cout << "]" << std::endl;
}
#endif
