/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-09-15 13:14:03
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-09-15 13:22:08
 * @Description  :
*********************************************/
#ifndef __LINEAR_LIST__
#define __LINEAR_LIST__


class LinearList {
private:
	// point to next of the tail element.
	int m_size;
	// m_array[0] is always empty, and the idx starts from 1.
	int m_array[101];

public:
	LinearList();

	int size() const;

	bool insert(int num, int idx);
	bool insert(int num);
	bool del(int idx);
	bool set(int num, int idx);
	
	// Return the index of num if the number is in the list.
	// Return -1 if it's not. Return the first one when have
	// multiple available values.
	int search(int num) const;

	// Get num from the index.
	int getNum(int idx) const;

	// print the list
	void print() const;

	// Merge list B and list A. Both A and B should be in descending order.
	// The return list will be in descending order too after merge.
	// Return an empty list if the input is invalid.
	static LinearList merge(LinearList& La, LinearList& Lb);

};


#endif
