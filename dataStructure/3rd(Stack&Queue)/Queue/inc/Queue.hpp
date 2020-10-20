#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__

class Queue {
private:
	int * m_queue;
	int m_head, m_tail, m_size;

public:
	Queue();
	~Queue();

	bool push(int data);
	bool pop();

	bool empty();
	int size();
	int front();
	int back();

	void print();
};

#endif
