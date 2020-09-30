#ifndef _LINKED_LIST_HPP_
#define _LINKED_LIST_HPP_

#include <iostream>

/***** Classes Declarations *****/

class Node;
class LinkedList;

/***** Classes Definitions *****/

class Node {
private:
	int m_data;
	Node * m_next;

	friend class LinkedList;

public:
	Node();
	Node(int data);
	~Node();

	Node * getNext() const;
	int getData() const;
};

class LinkedList {
private:
	// Head pointer of the list.
	Node * m_head;
	Node * m_tail;
	// Size of the list. Always point to next one of the tail element.
	int m_size;

public:
	LinkedList();
	LinkedList(std::initializer_list<int> list);
	LinkedList(LinkedList & obj);
	~LinkedList();

	int size() const;

	bool insert(int idx, int data);
	bool insert(int data);
	bool del(int idx);
	bool set(int idx, int data);
	bool isInList(int data);
	
	void print() const;

	bool merge(LinkedList & list);

	friend std::ostream & operator << (std::ostream & out, LinkedList& list);

};


/***** Operator overloading. *****/

std::ostream & operator << (std::ostream & out, LinkedList & list);
// std::ostream & operator >> (std::ostream & out, LinkedList& list);

#endif
