#include <string>
#include <cmath>
#include <iostream>
#include <c++/v1/__tuple>

class ComplexNumber
{
public:
    ComplexNumber(double real = 0, double imaginary = 0)
    {
        x = real;
        y = imaginary;
    }

    double Modulus() const
    {
        return std::sqrt(x * x + y * y);
    }

    void Display() const
    {
        std::cout << ToString() << std::endl;
    }

    std::string ToString() const
    {
        return std::to_string(x) + " + " + std::to_string(y) + " * i";
    }

    ComplexNumber operator+(ComplexNumber const &obj) const
    {
        ComplexNumber res;
        res.x = x + obj.x;
        res.y = y + obj.y;
        return res;
    }

    ComplexNumber operator-(ComplexNumber const &obj) const
    {
        ComplexNumber res;
        res.x = x - obj.x;
        res.y = y - obj.y;
        return res;
    }

    ComplexNumber operator*(ComplexNumber const &obj) const
    {
        ComplexNumber res;
        res.x = x * obj.x - y * obj.y;
        res.y = x * obj.y + y * obj.x;
        return res;
    }

    ComplexNumber operator/(ComplexNumber const &obj) const
    {
        ComplexNumber res;
        double denominator = obj.x * obj.x + obj.y * obj.y;
        res.x = (x * obj.x + y * obj.y) / denominator;
        res.y = (y * obj.x - x * obj.y) / denominator;
        return res;
    }

private:
    double x;
    double y;
};

bool readNumber(int &number)
{
    std::string s;
    getline(std::cin, s);

    try
    {
        number = stoi(s);
        return true;
    }
    catch (const std::exception &e)
    {
        return false;
    }
}

bool readComplexNumber(ComplexNumber &number, std::string const &numberName)
{
    std::cout << "Ввод числа " << numberName << std::endl;
    std::cout << "Введите вещественную часть:" << std::endl;

    int real;
    if (!readNumber(real))
    {
        std::cout << "Число " << numberName << " введено с ошибкой." << std::endl;
        return false;
    }

    std::cout << "Введите мнимую часть:" << std::endl;

    int imaginary;
    if (!readNumber(imaginary))
    {
        std::cout << "Число " << numberName << " введено с ошибкой." << std::endl;
        return false;
    }

    number = ComplexNumber(real, imaginary);

    return true;
}

int main(int argc, char const *argv[])
{
    std::cout << "Пожалуйста, введите три комплексных числа: a1, a2, a3" << std::endl;

    ComplexNumber a1;
    if (!readComplexNumber(a1, "a1"))
    {
        return 1;
    }
    std::cout << "a1 = " << a1.ToString() << std::endl << std::endl;

    ComplexNumber a2;
    if (!readComplexNumber(a2, "a2"))
    {
        return 1;
    }
    std::cout << "a2 = " << a2.ToString() << std::endl << std::endl;

    ComplexNumber a3;
    if (!readComplexNumber(a3, "a3"))
    {
        return 1;
    }
    std::cout << "a3 = " << a3.ToString() << std::endl << std::endl;

    ComplexNumber result = (a2 * a2 * a2 * a2) + ((a1 - a2) / (a3 * a1));

    std::cout << "Результат:" << std::endl;
    result.Display();

    return 0;
}
