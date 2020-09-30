#include "./../inc/LinkedList.hpp"
#include <iostream>

/***** Member functions of Node class. *****/
Node::Node() : m_data(0) {
	m_next = nullptr;
	// std::cout << "NodeCreated!" << std::endl;
}
// The data inside of node is defaultly 0.
Node::Node(int data) : m_data(data) {
	m_next = nullptr;
	// std::cout << "NodeCreated!" << std::endl;
}
Node::~Node() {
	// std::cout << "NodeDistructed!" << std::endl;
}

Node * Node::getNext() const {
	return m_next;
}
int Node::getData() const {
	return m_data;
}


/***** Member functions of LinkedList class. *****/

LinkedList::LinkedList() {
	m_head = new Node;
	m_tail = m_head;
	m_size = 0;
	// std::cout << "ListCreated!" << std::endl;
}
LinkedList::LinkedList(std::initializer_list<int> list) {
	m_head = new Node;
	m_tail = m_head;
	m_size = 0;

	for (auto item : list) {
		this -> insert(item);
	}
}

// Copy constructor
LinkedList::LinkedList(LinkedList & obj) {
	m_head = new Node;
	m_tail = m_head;
	m_size = 0;

	Node * p = obj.m_head -> m_next;
	for (; p != nullptr; p = p -> m_next) {
		insert(p->m_data);
	}
}

LinkedList::~LinkedList() {
	Node * p = m_head;
	Node * tmp = nullptr;
	while (p != nullptr) {
		tmp = p -> m_next;
		delete p;
		p = tmp;
	}
	// std::cout << "ListDistructed!" << std::endl;
}

int LinkedList::size() const {
	return m_size;
}

// Basic operations of LinkedList.

// Insert a node into list. The index of the node you insert will be 'idx' after
// operation. The index of list start from 0.
bool LinkedList::insert(int idx, int data) {
	if (idx < 0 || idx > m_size) {
		std::cout << "Index error!" << std::endl;
		return false;
	}

	// p will point to the node which you want to insert a node after it.
	Node * p = m_head;
	// Special judgement for inserting node to the tail.
	if (idx == m_size) {
		p = m_tail;
	}
	else {
		int count = 0;
		// To fine the node. p will point to the node which
		// you want to insert a node after it after the while loop.
		while (count != idx) {
			p = p -> m_next;
			count ++;
		}
	}
	
	Node * pp = new Node(data); // To create a new node.
	pp -> m_next = p -> m_next;
	p -> m_next = pp;

	// If a node have been inserted to the tail, make the m_tail pointer to point
	// the new position.
	if (p == m_tail) {
		m_tail = m_tail -> m_next;
	}

	m_size ++ ;

	return true;
}

// Overloading function of insert, defaultly insert after tail.
bool LinkedList::insert(int data) {
	return insert(m_size, data);
}

// Delete a node.
bool LinkedList::del(int idx) {
	if (idx < 0 || idx >= m_size) {
		std::cout << "Index error!" << std::endl;
		return false;
	}

	int count = 0;
	Node * p = m_head;
	// To fine the node. p will point to the predecessor node of the node that
	// you want to delete after the while loop.
	while (count != idx) {
		p = p -> m_next;
		count ++;
	}

	Node * tmp = p -> m_next;
	p -> m_next = p -> m_next -> m_next;
	delete tmp;
	m_size -- ;

	return true;
}

bool LinkedList::set(int idx, int data) {
	if (idx < 0 || idx >= m_size) {
		std::cout << "Index error!" << std::endl;
		return false;
	}

	int count = 0;
	Node * p = m_head -> m_next;
	// To fine the node. p will point to the node which
	// you want to set a new data for after the while loop.
	while (count != idx) {
		p = p -> m_next;
		count ++;
	}

	p -> m_data = data;

	return true;
}

// If data is in list, return true, otherwise return false.
bool LinkedList::isInList(int data) {
	// If list is empty.
	if (m_size == 0) {
		return false;
	}

	for (Node * p = m_head -> m_next; p != nullptr; p = p -> m_next) {
		if (p -> m_data == data) return true;
	}
	
	return false;
}

void LinkedList::print() const {
	// Pointer p point to the first node of the list.
	Node * p = m_head -> m_next;

	std::cout << "[";
	// Pointer p should not be a null pointer, and the node that p pointing should not
	// be the last node of list.
	// I wrote this judge for handle ", " output.
	while (p != nullptr && p -> m_next != nullptr) {
		std::cout << p -> m_data << ", ";
		p = p -> m_next;
	}
	// If list is empty, p will be null pointer, otherwise p will point to the
	// last node of list after the while loop above.
	if (p != nullptr) {
		std::cout << p -> m_data;
	}

	std::cout << "]" << std::endl;
}

bool LinkedList::merge(LinkedList & list) {
	Node * p = m_head -> m_next;
	Node * pl = list.m_head -> m_next;

	for (int idx = 0; p != nullptr && pl != nullptr; p = p -> m_next, ++ idx) {
		if (p -> m_data > pl -> m_data) {
			continue;
		}
		else {
			this -> insert(idx, pl -> m_data);
			pl = pl -> m_next;
		}
	}
	while (pl != nullptr) {
		this -> insert(pl -> m_data);
		pl = pl -> m_next;
	}


	return true;
}


/***** Operator overloading. *****/

std::ostream & operator << (std::ostream & out, LinkedList & list) {
	// Basicly use the same operation with print function of LinkedList.

	Node * p = list.m_head -> getNext();

	out << "[";

	while (p != nullptr && p -> getNext() != nullptr) {
		out << p -> getData() << ", ";
		p = p -> getNext();
	}

	if (p != nullptr) {
		out << p -> getData();
	}

	out << "]";

	return out;
}

