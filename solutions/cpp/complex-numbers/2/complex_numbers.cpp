#include "complex_numbers.h"
#include <cmath>

namespace complex_numbers {

// TODO: add your solution here
Complex::Complex(double real, double imag) : m_real(real), m_imag(imag) {}

double Complex::real() const
{
    return m_real;
}
    
double Complex::imag() const
{
    return m_imag;
}
    
Complex Complex::conj() const
{
    return Complex(m_real, -m_imag);
}

double Complex::abs() const
{
    return std::sqrt(std::pow(m_real, 2) + std::pow(m_imag, 2));
}

Complex Complex::operator+(const Complex& add) const
{
    return Complex(m_real + add.real(), m_imag + add.imag());
}

Complex Complex::operator+(double add) const
{
    return Complex(m_real + add, m_imag);
}

Complex operator+(double add1, const Complex& add2)
{
    return Complex(add1 + add2.real(), add2.imag());
}

Complex Complex::operator-(const Complex& sub) const
{
    return Complex(m_real - sub.real(), m_imag - sub.imag());
}

Complex Complex::operator-(double sub) const
{
    return Complex(m_real - sub, m_imag);
}

Complex operator-(double sub1, const Complex& sub2)
{
    return Complex(sub1 - sub2.real(), - sub2.imag());
}

Complex Complex::operator*(const Complex& mult) const
{
    return Complex(m_real * mult.real() - m_imag * mult.imag(),
                   m_imag * mult.real() + m_real * mult.imag());
}

Complex Complex::operator*(double mult) const
{
    return Complex(mult * m_real, mult * m_imag);
}

Complex operator*(double mult1, const Complex& mult2)
{
    return Complex(mult1 * mult2.real(), mult1 * mult2.imag());
}

Complex Complex::operator~() const
{
    return Complex(m_real, -m_imag) / std::pow(Complex::abs(), 2);
}

Complex Complex::operator/(const Complex& div) const
{
    return Complex((m_real * div.real() + m_imag * div.imag()) /                                   std::pow(div.abs(), 2),
                   (m_imag * div.real() - m_real * div.imag()) /                                   std::pow(div.abs(), 2));
}

Complex Complex::operator/(double div) const
{
    return Complex(m_real / div, m_imag / div);
}

Complex operator/(double div1, const Complex& div2)
{
    return div1 * (~div2);
}

Complex Complex::exp() const
{
    return std::exp(m_real) * Complex(std::cos(m_imag), std::sin(m_imag));
}
}  // namespace complex_numbers
