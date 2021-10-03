/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-10-01 14:29:25
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2021-09-18 16:58:55
 * @Description  :
*********************************************/

#ifndef _SINGEL_LINKED_LIST_HPP_
#define _SINGEL_LINKED_LIST_HPP_

#include <iostream>

/***** Classes Declarations *****/

template<typename T>
class Node;
template <typename T> class SingleLinkedList;

/***** Classes Definitions *****/

template<typename T>
class Node {
private:
	T m_data;
	Node<T> * m_next;

        friend class SingleLinkedList<T>;

      public:
	Node();
	Node(T data);
	~Node();

	Node<T> * getNext() const;
	T getData() const;
};

template <typename T> class SingleLinkedList {
private:
	// Head pointer of the list.
	Node<T> * m_head;
	Node<T> * m_tail;
	// Size of the list. Always point to next one of the tail element.
	int m_size;

public:
  SingleLinkedList();
  SingleLinkedList(std::initializer_list<T> list);
  ~SingleLinkedList();

  int size() const;

  bool insert(int idx, T data);
  bool insert(T data);
  bool del(int idx);
  bool set(int idx, T data);
  bool isInList(T data);

  void print() const;

  T & operator[](int idx);
  const int &operator[](int idx) const;

  bool merge(SingleLinkedList &list);
};

/***** Member functions of Node class. *****/

template<typename T>
Node<T>::Node() {
	m_next = nullptr;
}
// The data inside of node is defaultly 0.
template<typename T>
Node<T>::Node(T data) : m_data(data) {
	m_next = nullptr;
}
template<typename T>
Node<T>::~Node() {
}

template<typename T>
Node<T> * Node<T>::getNext() const {
	return m_next;
}
template<typename T>
T Node<T>::getData() const {
	return m_data;
}


/***** Member functions of LinkedList class. *****/

template <typename T> SingleLinkedList<T>::SingleLinkedList() {
  m_head = new Node<T>;
  m_tail = m_head;
  m_size = 0;
}
template <typename T>
SingleLinkedList<T>::SingleLinkedList(std::initializer_list<T> list) {
  m_head = new Node<T>;
  m_tail = m_head;
  m_size = 0;

  for (auto item : list) {
    this->insert(item);
  }
}

template <typename T> SingleLinkedList<T>::~SingleLinkedList() {
  Node<T> *p = m_head;
  Node<T> *tmp = nullptr;
  while (p != nullptr) {
    tmp = p->m_next;
    delete p;
    p = tmp;
  }
  // std::cout << "ListDistructed!" << std::endl;
}

template <typename T> int SingleLinkedList<T>::size() const { return m_size; }

// Basic operations of LinkedList.

// Insert a node into list. The index of the node you insert will be 'idx' after
// operation. The index of list start from 0.
template <typename T> bool SingleLinkedList<T>::insert(int idx, T data) {
  if (idx < 0 || idx > m_size) {
    std::cout << "Index error!" << std::endl;
    return false;
  }

  // p will point to the node which you want to insert a node after it.
  Node<T> *p = m_head;
  // Special judgement for inserting node to the tail.
  if (idx == m_size) {
    p = m_tail;
  } else {
    int count = 0;
    // To fine the node. p will point to the node which
    // you want to insert a node after it after the while loop.
    while (count != idx) {
      p = p->m_next;
      count++;
    }
  }

  Node<T> *pp = new Node<T>(data); // To create a new node.
  pp->m_next = p->m_next;
  p->m_next = pp;

  // If a node have been inserted to the tail, make the m_tail pointer to point
  // the new position.
  if (p == m_tail) {
    m_tail = m_tail->m_next;
  }

  m_size++;

  return true;
}

// Overloading function of insert, defaultly insert after tail.
template <typename T> bool SingleLinkedList<T>::insert(T data) {
  return insert(m_size, data);
}

// Delete a node.
template <typename T> bool SingleLinkedList<T>::del(int idx) {
  if (idx < 0 || idx >= m_size) {
    std::cout << "Index error!" << std::endl;
    return false;
  }

  int count = 0;
  Node<T> *p = m_head;
  // To fine the node. p will point to the predecessor node of the node that
  // you want to delete after the while loop.
  while (count != idx) {
    p = p->m_next;
    count++;
  }

  Node<T> *tmp = p->m_next;
  p->m_next = p->m_next->m_next;
  delete tmp;
  m_size--;

  return true;
}

template <typename T> bool SingleLinkedList<T>::set(int idx, T data) {
  if (idx < 0 || idx >= m_size) {
    std::cout << "Index error!" << std::endl;
    return false;
  }

  int count = 0;
  Node<T> *p = m_head->m_next;
  // To fine the node. p will point to the node which
  // you want to set a new data for after the while loop.
  while (count != idx) {
    p = p->m_next;
    count++;
  }

  p->m_data = data;

  return true;
}

// If data is in list, return true, otherwise return false.
template <typename T> bool SingleLinkedList<T>::isInList(T data) {
  // If list is empty.
  if (m_size == 0) {
    return false;
  }

  for (Node<T> *p = m_head->m_next; p != nullptr; p = p->m_next) {
    if (p->m_data == data)
      return true;
  }

  return false;
}

template <typename T> void SingleLinkedList<T>::print() const {
  // Pointer p point to the first node of the list.
  Node<T> *p = m_head->m_next;

  std::cout << "[";
  // Pointer p should not be a null pointer, and the node that p pointing should
  // not be the last node of list. I wrote this judge for handle ", " output.
  while (p != nullptr && p->m_next != nullptr) {
    std::cout << p->m_data << ", ";
    p = p->m_next;
  }
  // If list is empty, p will be null pointer, otherwise p will point to the
  // last node of list after the while loop above.
  if (p != nullptr) {
    std::cout << p->m_data;
  }

  std::cout << "]" << std::endl;
}

// Overloading function for [] to access nodes of list.
// Return the data of head node (which is a rubbish value) if index is no available.
template <typename T> T &SingleLinkedList<T>::operator[](int idx) {
  if (idx < 0 || idx >= m_size) {
    std::cout << "Index error!" << std::endl;
    return m_head->m_data;
  }

  Node<T> *p = m_head->m_next;
  for (int i = 0; i < idx; ++i) {
    p = p->m_next;
  }

  return p->m_data;
}
template <typename T>
const int &SingleLinkedList<T>::operator[](int idx) const {
  if (idx < 0 || idx >= m_size) {
    std::cout << "Index error!" << std::endl;
    return m_head->m_data;
  }

  Node<T> *p = m_head->m_next;
  for (int i = 0; i < idx; ++i) {
    p = p->m_next;
  }

  return p->m_data;
}

template <typename T>
bool SingleLinkedList<T>::merge(SingleLinkedList<T> &list) {
  Node<T> *p = m_head->m_next;
  Node<T> *pl = list.m_head->m_next;

  for (int idx = 0; p != nullptr && pl != nullptr; p = p->m_next, ++idx) {
    if (p->m_data > pl->m_data) {
      continue;
    } else {
      this->insert(idx, pl->m_data);
      pl = pl->m_next;
    }
  }
  while (pl != nullptr) {
    this->insert(pl->m_data);
    pl = pl->m_next;
  }

  return true;
}

#endif
