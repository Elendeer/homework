/*
 * @Author: Elendeer
 * @Date: 2020-05-28 21:06:31
 * @LastEditors: Elendeer
 * @LastEditTime: 2020-05-30 17:03:28
 * @Description: file content
 */
#ifndef STRANGE_H_
#define STRANGE_H_

struct StrA {
	int m_num;
	StrA (int num = 0) : m_num(num) {}
};
// for test
StrA* fun(StrA para);

#endif