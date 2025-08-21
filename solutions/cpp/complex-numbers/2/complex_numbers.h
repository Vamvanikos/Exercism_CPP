#if !defined(COMPLEX_NUMBERS_H)
#define COMPLEX_NUMBERS_H

namespace complex_numbers {

// TODO: add your solution here
class Complex {
public:
    Complex(double real, double imag);
    double real() const;
    double imag() const;
    
    Complex operator+(const Complex& add) const;
    Complex operator+(double add) const;
    Complex operator-(const Complex& sub) const;
    Complex operator-(double sub) const;
    Complex operator*(const Complex& mult) const;
    Complex operator*(double mult) const;
    Complex operator/(const Complex& div) const;
    Complex operator/(double div) const;
    Complex operator~() const; // 1/z

    Complex conj() const;
    double abs() const;
    Complex exp() const;
private:
    double m_real;
    double m_imag;
};

Complex operator+(double add1, const Complex& add2);
Complex operator-(double sub1, const Complex& sub2);
Complex operator*(double mult1, const Complex& mult2);
Complex operator/(double div1, const Complex& div2);

}  // namespace complex_numbers

#endif  // COMPLEX_NUMBERS_H
