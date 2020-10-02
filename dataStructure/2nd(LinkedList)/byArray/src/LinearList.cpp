/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-09-15 13:14:03
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-09-15 13:21:41
 * @Description  :
*********************************************/
#include <iostream>
#include "./../inc/LinearList.hpp"

LinearList::LinearList() : m_size(1) {}

bool LinearList::insert(int num, int idx) {
	if (idx > m_size || idx < 1) {
		std::cout << "invalid idx" << std::endl;
		return false;
	}
	if (m_size > 100) {
		std::cout << "list is full" << std::endl;
		return false;
	}

	m_array[idx] = num;
	m_size ++ ;
	return true;
}
bool LinearList::insert(int num) {
	if (m_size > 100) {
		std::cout << "list is full" << std::endl;
		return false;
	}
	m_array[m_size] = num;
	m_size ++ ;
	return true;
}

int LinearList::size() const{
	return m_size;
}

bool LinearList::del(int idx) {
	if (idx >= m_size || idx < 1) {
		std::cout << "invalid idx" << std::endl;
		return false;
	}
	if (m_size <= 1) {
		std::cout << "list is empty" << std::endl;
		return false;
	}

	for (int i = idx; i < m_size; ++ i ) {
		m_array[i] = m_array[i + 1];
	}
	m_size -- ;
	return true;

}

bool LinearList::set(int num, int idx) {
	if (idx > m_size || idx < 1) {
		std::cout << "invalid idx" << std::endl;
		return false;
	}

	m_array[idx] = num;

	return true;
}

int LinearList::search(int num) const {
	for (int i = 1; i < m_size; ++ i) {
		if (m_array[i] == num) return i;
	}
	return -1;
}

int LinearList::getNum(int idx) const {
	if (idx >= m_size || idx < 1) {
		std::cout << "invalid idx" << std::endl;
		return -1;
	}
	return m_array[idx];
}

void LinearList::print() const{
	std::cout << "[";
	for (int i = 1; i < m_size - 1; ++ i ) {
		std::cout << m_array[i] << ", ";
	}
	std::cout << m_array[m_size - 1];
	std::cout << "]" << std::endl;
}

LinearList LinearList::merge(LinearList& La, LinearList& Lb) {
	LinearList Lc;
	if (La.size() + Lb.size() - 2 > 100) {
		std::cout << "List will out of range after merge!" << std::endl;
		return Lc;
	}

	int i = 1, j = 1;

	while (i < La.size() && j < Lb.size()) {
		if (La.getNum(i) > Lb.getNum(j)) {
			Lc.insert(La.getNum(i), Lc.size());
			i ++;
		}
		else {
			Lc.insert(Lb.getNum(j), Lc.size());
			j ++;
		}
	}

	while (i < La.size()) {
		Lc.insert(La.getNum(i), Lc.size());
		i ++;
	}
	while (j < Lb.size()) {
		Lc.insert(Lb.getNum(j), Lc.size());
		j ++;
	}



	return Lc;
}
