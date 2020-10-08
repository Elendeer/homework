/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-10-01 14:29:25
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-10-02 21:17:07
 * @Description  :
*********************************************/

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
	~LinkedList();

	int size() const;


	// Basic operations of LinkedList.

	// Insert a node into list. The index of the node you insert will be 'idx' after
	// operation. The index of list start from 0.
	bool insert(int idx, int data);

	// Overloading function of insert, defaultly insert after tail.
	bool insert(int data);

	// Delete a node.
	bool del(int idx);

	bool set(int idx, int data);

	// If data is in list, return true, otherwise return false.
	bool isInList(int data);

	void print() const;


	// Overloading function for [] to access nodes of list.
	// Return the data of head node (which is 0) if index is no available.
	int & operator[](int idx);
	const int & operator[](int idx) const;

	bool merge(LinkedList & list);

	friend std::ostream & operator << (std::ostream & out, LinkedList& list);

};


/***** Operator overloading. *****/

std::ostream & operator << (std::ostream & out, LinkedList & list);
// std::ostream & operator >> (std::ostream & out, LinkedList& list);

#endif
