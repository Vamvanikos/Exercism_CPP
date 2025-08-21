#pragma once
#include <cmath>

namespace complex_numbers {

class Complex {
public:
    Complex(double r, double i) : m_real(r), m_imag(i) {};

    double real() const;
    double imag() const;

    Complex conj() const;
    double abs() const;
    Complex exp() const;
    Complex reciprocal() const;
    
    Complex operator+(const Complex& c) const;
    Complex operator+(double d) const;
    Complex operator-(const Complex& c) const;
    Complex operator-(double d) const;
    Complex operator*(const Complex& c) const;
    Complex operator*(double d) const;
    Complex operator/(const Complex& c) const;
    Complex operator/(double d) const;

private:
    double m_real;
    double m_imag;
};

Complex operator+(double d, const Complex& c);

Complex operator-(double d, const Complex& c);

Complex operator*(double d, const Complex& c);

Complex operator/(double d, const Complex& c);

}  // namespace complex_numbers
