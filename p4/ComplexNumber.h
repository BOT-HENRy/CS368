#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include <iostream>
using namespace std;

class ComplexNumber {

  public:

    // constructors
    ComplexNumber();
    ComplexNumber(double real_part, double imaginary_part);
    ComplexNumber(const ComplexNumber & rhs);

    // named member functions
    void print(ostream & out = cout) const;
    bool equals(const ComplexNumber & rhs) const;

    // assignment operators
    const ComplexNumber & operator=(const ComplexNumber & rhs);
    const ComplexNumber & operator+=(const ComplexNumber & rhs);
    const ComplexNumber & operator-=(const ComplexNumber & rhs);
    const ComplexNumber & operator*=(const ComplexNumber & rhs);

  private:
    double real;      
    double imag; 
};

// arithmetic operators
ComplexNumber operator+(const ComplexNumber & lhs, const ComplexNumber & rhs);
ComplexNumber operator-(const ComplexNumber & lhs, const ComplexNumber & rhs);
ComplexNumber operator*(const ComplexNumber & lhs, const ComplexNumber & rhs);

// relational operators
bool operator==(const ComplexNumber & lhs, const ComplexNumber & rhs);
bool operator!=(const ComplexNumber & lhs, const ComplexNumber & rhs);

// I/O operators
ostream & operator<<(ostream & out, const ComplexNumber & n);
istream & operator>>(istream & in, ComplexNumber & n);

#endif
