#ifndef _STACK_HPP_
#define _STACK_HPP_

#include <iostream>

class Stack {
private:
	int* m_stack;
	int m_top;
public:
	Stack();
	Stack(std::initializer_list<int> list);
	Stack(int len);
	~Stack();

	// Basic operations.

	bool push(int data);
	bool pop();
	void clear();

	
	// Get things.

	bool empty() const;
	int top() const;
	int size();

	void print();
};

#endif
