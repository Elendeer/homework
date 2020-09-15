/*********************************************
 * @Author       : Daniel_Elendeer
 * @Date         : 2020-09-10 14:45:06
 * @LastEditors  : Daniel_Elendeer
 * @LastEditTime : 2020-09-10 14:48:49
 * @Description  :
*********************************************/
#ifndef _COMPLEX_HPP_
#define _COMPLEX_HPP_

#include <iostream>

class Complex {

private:
	double m_real;
	double m_image;

public:
	Complex(double real = 0, double image = 0);
	Complex(const Complex& obj);

	double getReal() const;
	double getImage() const;

	void setReal(double real);
	void setImage(double image);

	void show();

	Complex operator + (const Complex& obj);
	Complex operator - (const Complex& obj);
	Complex operator * (const Complex& obj);
	Complex operator / (const Complex& obj);

	friend std::istream& operator >> (std::istream& input, Complex& obj);
	friend std::ostream& operator << (std::ostream& output, Complex& obj);
};

std::istream& operator >> (std::istream& input, Complex& obj);
std::ostream& operator << (std::ostream& output, Complex& obj);

#endif
