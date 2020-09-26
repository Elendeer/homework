#ifndef _LINKED_LIST_HPP_
#define _LINKED_LIST_HPP_

class Node {
private:
	int m_data;
	Node * m_next;

	friend class LinkedList;

public:
	Node();
	Node(int data);
	~Node();
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
	~LinkedList();

	int size() const;

	bool insert(int idx, int data);
	bool insert(int data);
	bool del(int idx);
	bool set(int idx, int data);
	bool isInList(int data);
	
	void print() const;

};

#endif
