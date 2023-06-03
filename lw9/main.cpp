#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#include <float.h>

const double X_MIN = -2.0;
const double X_MAX = 4.0;
const double X_STEP = 0.3;

const int RANDOM_MIN = -100;
const int RANDOM_MAX = 100;

class DivideByException : public std::runtime_error
{
public:
    DivideByException() : std::runtime_error("Деление на ноль в математике запрещено!") {}
};

class OutOfBoundsException : public std::runtime_error
{
public:
    OutOfBoundsException() : std::runtime_error("Переполнение типа, будьте аккуратны.") {}
};

class LogWithNegativeOrZeroException : public std::runtime_error
{
public:
    LogWithNegativeOrZeroException() : std::runtime_error("Число для вычисления логарифма должно быть положительным!") {}
};

class IndexOutOfBoundsException : public std::runtime_error
{
public:
    IndexOutOfBoundsException() : std::runtime_error("Индекс выходит за пределы массива =)") {}
};

std::vector<double> CreateListA()
{
    double x = X_MIN;
    std::vector<double> result;

    while (x <= X_MAX)
    {
        std::cout << "x = " << x << std::endl;
        double resultNumber = 0;

        try
        {
            if (DBL_MAX - 1 < x)
            {
                throw OutOfBoundsException();
            }

            double divider = x + 1;

            if (divider == 0)
            {
                throw DivideByException();
            }

            double data = 1 / divider;

            if (x <= 0)
            {
                throw LogWithNegativeOrZeroException();
            }

            resultNumber = log(x);
        }
        catch (const std::runtime_error &e)
        {
            std::cerr << e.what() << std::endl;
        }

        x += X_STEP;
        result.push_back(resultNumber);
    }

    return result;
}

std::vector<int> CreateListB(int size)
{
    std::vector<int> result;

    for (size_t i = 0; i < size; i++)
    {
        int randomNumber = rand() % (RANDOM_MAX - RANDOM_MIN + 1) + RANDOM_MIN;
        result.push_back(randomNumber);
    }

    return result;
}

std::vector<double> CreateListC(std::vector<double> listA, std::vector<int> listB, int size)
{
    std::vector<double> result;

    for (size_t i = 0; i < size; i++)
    {
        double resultNumber = 0;

        try
        {
            int index = i + 1;
            if (index >= listB.size())
            {
                throw IndexOutOfBoundsException();
            }

            int divider = listB[index];

            if (divider == 0)
            {
                throw DivideByException();
            }

            resultNumber = listA[i] / divider;
        }
        catch (const std::runtime_error &e)
        {
            std::cerr << e.what() << '\n';
        }

        result.push_back(resultNumber);
    }

    return result;
}

int main(int argc, char const *argv[])
{
    std::vector<double> listA = CreateListA();
    std::vector<int> listB = CreateListB(listA.size() + 1);
    std::vector<double> listC = CreateListC(listA, listB, listB.size() + 1);

    std::cout << "Лист A:" << std::endl;
    for (size_t i = 0; i < listA.size(); i++)
    {
        std::cout << listA[i] << std::endl;
    }

    std::cout << std::endl
              << "Лист B:" << std::endl;
    for (size_t i = 0; i < listB.size(); i++)
    {
        std::cout << listB[i] << std::endl;
    }

    std::cout << std::endl
              << "Лист C:" << std::endl;
    for (size_t i = 0; i < listC.size(); i++)
    {
        std::cout << listC[i] << std::endl;
    }

    return 0;
}
