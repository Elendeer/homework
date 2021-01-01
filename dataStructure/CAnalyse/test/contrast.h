//constrast.h
#pragma once
template<typename T>
class Contrast
{
public:
	Contrast(T a, T b);
	T max();
	T min();
	void put();
private:
	T x, y;
};

//constrast.cpp
#include "contrast.h"
#include<iostream>
using namespace std;
template<typename T>
Contrast <T>::Contrast(T a, T b)
{
	x = a; y = b;
}
template<typename T>
T Contrast <T>::max()
{
	if (x > y)	return x;
	else return y;
}
template<typename T>
T Contrast <T>::min()
{
	if (x < y)	return x;
	else return y;
}
template<typename T>
void Contrast<T>::put()
{
	cout << "大数" << max() << "小数：" << min() << endl;
}