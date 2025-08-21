#include "complex_numbers.h"

namespace complex_numbers {

double Complex::real() const { return m_real; }
double Complex::imag() const { return m_imag; }

Complex Complex::conj() const
{
    return Complex(m_real, -m_imag);
}

double Complex::abs() const
{
    return std::sqrt(m_real * m_real + m_imag * m_imag);
}

Complex Complex::exp() const
{
    return Complex(std::exp(m_real) * std::cos(m_imag),
                   std::exp(m_real) * std::sin(m_imag));
}

Complex Complex::reciprocal() const
{
    return Complex(m_real, -m_imag) / (Complex::abs() * Complex::abs());
}

Complex Complex::operator+(const Complex& c) const
{
    return Complex(m_real + c.m_real, m_imag + c.m_imag);
}

Complex Complex::operator+(double d) const
{
    return Complex(m_real + d, m_imag);
}

Complex Complex::operator-(const Complex& c) const
{
    return Complex(m_real - c.m_real, m_imag - c.m_imag);
}

Complex Complex::operator-(double d) const
{
    return Complex(m_real - d, m_imag);
}

Complex Complex::operator*(const Complex& c) const
{
    return Complex(m_real * c.m_real - m_imag * c.m_imag,
                   m_imag * c.m_real + m_real * c.m_imag);
}

Complex Complex::operator*(double d) const
{
    return Complex(m_real * d, m_imag * d);
}

Complex Complex::operator/(const Complex& c) const
{
    return Complex((m_real * c.m_real + m_imag * c.m_imag)/(c.abs() * c.abs()),
                   (m_imag * c.m_real - m_real * c.m_imag)/(c.abs() * c.abs()));
}

Complex Complex::operator/(double d) const
{
    return Complex(m_real / d, m_imag / d);
}


Complex operator+(double d, const Complex& c)
{
    return Complex(c.real() + d, c.imag());
}

Complex operator-(double d, const Complex& c)
{
    return Complex(d - c.real(), -c.imag());
}

Complex operator*(double d, const Complex& c)
{
    return Complex(d * c.real(), d * c.imag());
}

Complex operator/(double d, const Complex& c)
{
    return d * c.reciprocal();
}

}  // namespace complex_numbers
