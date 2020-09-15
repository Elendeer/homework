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
	int getNum(int idx) const;

	// print the list
	void print() const;


};


#endif
