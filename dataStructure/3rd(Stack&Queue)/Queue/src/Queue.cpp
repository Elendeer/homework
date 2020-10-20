#include "../inc/Queue.hpp"

#include <iostream>

Queue::Queue() : m_head(0), m_tail(0) {
	if (!(m_queue = new int [101])) {
		std::cout << "Memory error" << std::endl;
	}
	std::cout << "Created" << std::endl;
}
Queue::~Queue() {
	delete [] m_queue;
	std::cout << "Destoryed" << std::endl;
}


bool Queue::push(int data) {
	if (m_tail + 1 <= 100) {
		m_queue[m_tail ++] = data;
		return true;
	}
	return false;
}

bool Queue::pop() {
	if (m_head < m_tail) {
		m_head ++;
		return true;
	}
	return false;
}

bool Queue::empty() {
	if (this -> size() != 0) {
		return false;
	}
	return true;
}

int Queue::size() {
	return m_tail - m_head;
}

int Queue::front() {
	return m_queue[m_head];
}

int Queue::back() {
	return m_queue[m_tail - 1];
}


void Queue::print() {
	std::cout << "[" ;
	for (int i = m_head; i < m_tail - 1; ++ i ) {
		std::cout << m_queue[i] << ", ";
	}
	if (m_tail - 1 >= m_head) {
		std::cout << m_queue[m_tail - 1];
	}
	std::cout << "]" << std::endl;
}
