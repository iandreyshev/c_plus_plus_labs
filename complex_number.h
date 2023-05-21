#pragma once
#include <c++/v1/__tuple>
#include <cmath>
#include <iostream>

class ComplexNumber
{
public:
    ComplexNumber(int real = 0, int imaginary = 0);

    double Modulus() const;
    void Display() const;

    ComplexNumber operator+(ComplexNumber const &obj) const;
    ComplexNumber operator-(ComplexNumber const &obj) const;
    ComplexNumber operator*(ComplexNumber const &obj) const;
    ComplexNumber operator/(ComplexNumber const &obj) const;

private:
    int x;
    int y;
};
