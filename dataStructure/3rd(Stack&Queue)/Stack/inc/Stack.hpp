#ifndef _STACK_HPP_
#define _STACK_HPP_

#include <iostream>

class Stack {
private:
	// pointer of stack array.
	int* m_stack;

	// index of top element.
	int m_top;
public:
	Stack();
	Stack(std::initializer_list<int> list);
	Stack(int len);
	~Stack();

	// Basic operations.

	// Push a data into the stack, return fales if memory overfloat.
	bool push(int data);

	// Pop a data from the stack, return false if stack is empty.
	bool pop();

	// Clear the stack, pop out everythings.
	void clear();

	
	// Get things.

	// Returns ture if stack is empty.
	bool empty() const;

	// Returns the data which in top of the stack.
	int top() const;

	// Returns the number of elements in the stack.
	int size();

	// Print the stack.
	void print();
};

#endif
