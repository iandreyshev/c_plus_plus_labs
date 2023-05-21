#include <cmath>
#include <iostream>
#include "complex_number.h"

ComplexNumber::ComplexNumber(int real = 0, int imaginary = 0)
{
    x = real;
    y = imaginary;
}

double ComplexNumber::Modulus() const
{
    return std::sqrt(x * x + y * y);
}

void ComplexNumber::Display() const
{
    std::cout << std::to_string(x) << " + " << std::to_string(y) << " * i" << std::endl;
}

ComplexNumber ComplexNumber::operator+(ComplexNumber const &obj) const
{
    ComplexNumber res;
    res.x = x + obj.x;
    res.y = y + obj.y;
    return res;
}

ComplexNumber ComplexNumber::operator-(ComplexNumber const &obj) const
{
    ComplexNumber res;
    res.x = x - obj.x;
    res.y = y - obj.y;
    return res;
}

ComplexNumber ComplexNumber::operator*(ComplexNumber const &obj) const
{
    ComplexNumber res;
    res.x = x * obj.x - y * obj.y;
    res.y = x * obj.y + y * obj.x;
    return res;
}

ComplexNumber ComplexNumber::operator/(ComplexNumber const &obj) const
{
    ComplexNumber res;
    double denominator = obj.x * obj.x + obj.y * obj.y;
    res.x = (x * obj.x + y * obj.y) / denominator;
    res.y = (y * obj.x - x * obj.y) / denominator;
    return res;
}
