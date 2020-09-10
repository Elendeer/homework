#include <iostream>
#include "./../inc/Complex.hpp"

Complex::Complex(double real, double image) : m_real(real), m_image(image) {}
Complex::Complex(const Complex& obj) {
	m_real = obj.getReal();
	m_image = obj.getImage();
}

double Complex::getReal() const{
	return m_real;
}
double Complex::getImage() const{
	return m_image;
}

void Complex::setReal(double real) {
	m_real = real;
}
void Complex::setImage(double image) {
	m_image = image;
}

void Complex::show() {
	std::cout << "real : " << m_real << std::endl;
	std::cout << "image : " << m_image << std::endl;
}

// reload
Complex Complex::operator + (const Complex& obj) {
	Complex ans(m_real + obj.getReal(), m_image + obj.getImage());
	return ans;
}
Complex Complex::operator - (const Complex& obj) {
	Complex ans(m_real - obj.getReal(), m_image - obj.getImage());
	return ans;
}

Complex Complex::operator * (const Complex& obj) {
	Complex ans(m_real * obj.getReal() - m_image * obj.getImage(),
			m_real * obj.getImage() + m_image * obj.getReal());
	return ans;
}
Complex Complex::operator / (const Complex& obj) {
	Complex ans((m_real * obj.getReal() + m_image * obj.getImage()) /
				(obj.getReal() * obj.getReal() + obj.getImage() * obj.getImage())
				,(m_real * (-obj.getImage()) + obj.getReal() * m_image) /
				(obj.getReal() * obj.getReal() + obj.getImage() * obj.getImage()));
	return ans;
}

std::istream& operator >> (std::istream& input, Complex& obj) {
	return input >> obj.m_real >> obj.m_image;
}
std::ostream& operator << (std::ostream& output, Complex& obj) {
	return output << "real : " << obj.m_real << std::endl
		<< "image : " << obj.m_image << std::endl;
}
