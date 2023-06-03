#include <string>
#include <cmath>
#include <iostream>
#include <c++/v1/__tuple>

const std::string COMMAND_INCREASE_ANGLE_A = "1";
const std::string COMMAND_INCREASE_ANGLE_B = "2";
const std::string COMMAND_DECREASE_ANGLE_A = "3";
const std::string COMMAND_DECREASE_ANGLE_B = "4";
const std::string COMMAND_PRINT_HEIGHTS = "5";
const std::string COMMAND_PRINT_SIDES = "6";
const std::string COMMAND_VALIDATE = "7";
const std::string COMMAND_HELP = "help";
const std::string COMMAND_EXIT = "exit";

struct TriangleSides
{
    double ab;
    double bc;
    double ca;

    TriangleSides(double newAB, double newBC, double newCA)
        : ab(newAB),
          bc(newBC),
          ca(newCA) {}
};

/**
 * Triangle:
 *      C
 *     /\
 *    /  \
 *   /    \
 * B ------ A
 */
class Triangle
{
public:
    Triangle(double side = 1, int angleA = 60, int angleB = 60)
    {
        m_side = side;
        m_angleA = angleA;
        m_angleB = angleB;
    }

    int GetAngleA() const
    {
        return m_angleA;
    }

    int GetAngleB() const
    {
        return m_angleB;
    }

    int GetAngleC() const
    {
        return 180 - m_angleA - m_angleB;
    }

    int GetSide() const
    {
        return m_side;
    }

    bool SetAngleA(int angle)
    {
        if (angle < 0)
        {
            std::cout << "Угол треугольника не может быть отрицательным числом." << std::endl;
            return false;
        }

        m_angleA = angle;

        return true;
    }

    bool IncreaseAngleA(int angle)
    {
        return SetAngleA(m_angleA + angle);
    }

    bool IncreaseAngleB(int angle)
    {
        return SetAngleB(m_angleB + angle);
    }

    bool SetAngleB(int angle)
    {
        if (angle < 0)
        {
            std::cout << "Угол треугольника не может быть отрицательным числом." << std::endl;
            return false;
        }

        m_angleB = angle;

        return true;
    }

    bool SetSide(int side)
    {
        if (side <= 0)
        {
            std::cout << "Сторона треугольника может быть только положительным числом." << std::endl;
            return false;
        }

        m_side = side;

        return true;
    }

    TriangleSides GetHeights() const
    {
        TriangleSides sides = GetSides();

        double radiansB = m_angleB * M_PI / 180.0;
        double heightAB = sides.bc * sin(radiansB);

        double radiansC = GetAngleC() * M_PI / 180.0;
        double heightBC = sides.ca * sin(radiansC);

        double radiansA = m_angleA * M_PI / 180.0;
        double heightAC = sides.ab * sin(radiansA);

        return TriangleSides(heightAB, heightBC, heightAC);
    }

    TriangleSides GetSides() const
    {
        double radiansA = m_angleA * M_PI / 180.0;

        double radiansC = GetAngleC() * M_PI / 180.0;
        double sideBC = (m_side * sin(radiansA)) / sin(radiansC);

        double radiansB = m_angleB * M_PI / 180.0;
        double sideAC = (m_side * sin(radiansB)) / sin(radiansC);

        return TriangleSides(m_side, sideBC, sideAC);
    }

    bool IsValid() const
    {
        return m_side > 0 &&
               m_angleA >= 0 &&
               m_angleB >= 0 &&
               m_angleA + m_angleB < 180;
    }

private:
    double m_side;
    int m_angleA;
    int m_angleB;
};

void getTriangleSides(double side, double angle1, double angle2, double &adjacentSide, double &oppositeSide)
{
    double radians1 = angle1 * M_PI / 180.0;
    double radians2 = angle2 * M_PI / 180.0;
    double height = side * std::sin(radians1);
    adjacentSide = height / std::tan(radians2);
    oppositeSide = std::sqrt(std::pow(side, 2) - std::pow(height, 2));
}

void PrintHelp()
{
    std::cout << "Список команд:" << std::endl
              << COMMAND_INCREASE_ANGLE_A << " - увеличить угол A" << std::endl
              << COMMAND_INCREASE_ANGLE_B << " - увеличить угол B" << std::endl
              << COMMAND_DECREASE_ANGLE_A << " - уменьшить угол A" << std::endl
              << COMMAND_DECREASE_ANGLE_B << " - уменьшить угол B" << std::endl
              << COMMAND_PRINT_HEIGHTS << " - вывод высот" << std::endl
              << COMMAND_PRINT_SIDES << " - вывод сторон" << std::endl
              << COMMAND_VALIDATE << " - узнать валидность фигуры" << std::endl
              << COMMAND_HELP << " - вывод списка команд" << std::endl
              << COMMAND_EXIT << " - выход" << std::endl;
}

bool ReadAngle(int &angle)
{
    std::string angleStr;

    if (!getline(std::cin, angleStr))
    {
        return false;
    }

    try
    {
        angle = std::stoi(angleStr);
    }
    catch (const std::exception &e)
    {
        std::cout << "Угол введен с ошибкой." << std::endl;
        return false;
    }

    return true;
}

bool IncreaseAngleA(Triangle &triangle)
{
    std::cout << "Введите угол, на который нужно увеличить угол A:" << std::endl;
    int angle;

    if (!ReadAngle(angle))
    {
        return false;
    }

    return triangle.IncreaseAngleA(angle);
}

bool IncreaseAngleB(Triangle &triangle)
{
    std::cout << "Введите угол, на который нужно увеличить угол B:" << std::endl;
    int angle;

    if (!ReadAngle(angle))
    {
        return false;
    }

    return triangle.IncreaseAngleB(angle);
}

bool DecreaseAngleA(Triangle &triangle)
{
    std::cout << "Введите угол, на который нужно уменьшить угол A:" << std::endl;
    int angle;

    if (!ReadAngle(angle))
    {
        return false;
    }

    return triangle.IncreaseAngleA(-angle);
}

bool DecreaseAngleB(Triangle &triangle)
{
    std::cout << "Введите угол, на который нужно уменьшить угол B:" << std::endl;
    int angle;

    if (!ReadAngle(angle))
    {
        return false;
    }

    return triangle.IncreaseAngleB(-angle);
}

void PrintTriangleInfo(Triangle const &triangle)
{
    std::cout << "Сторона AB = " << triangle.GetSide() << std::endl
              << "Угол A = " << triangle.GetAngleA() << "°" << std::endl
              << "Угол B = " << triangle.GetAngleB() << "°" << std::endl
              << "Угол C = " << triangle.GetAngleC() << "°" << std::endl;
}

bool PrintTriangleHeights(Triangle const &triangle)
{
    if (!triangle.IsValid())
    {
        std::cout << "Нельзя вычислить высоты у невалидного треугольника." << std::endl;
        return false;
    }

    TriangleSides heights = triangle.GetHeights();
    std::cout << "Высота из угла A = " << heights.bc << std::endl
              << "Высота из угла B = " << heights.ca << std::endl
              << "Высота из угла C = " << heights.ab << std::endl;

    return true;
}

bool PrintTriangleSides(Triangle const &triangle)
{
    if (!triangle.IsValid())
    {
        std::cout << "Нельзя вычислить стороны у невалидного треугольника." << std::endl;
        return false;
    }

    TriangleSides sides = triangle.GetSides();
    std::cout << "AB = " << sides.ab << std::endl
              << "BC = " << sides.bc << std::endl
              << "CA = " << sides.ca << std::endl;

    return true;
}

void ValidateTriangle(Triangle const &triangle)
{
    if (triangle.IsValid())
    {
        std::cout << "Треугольник валиден." << std::endl;
    }
    else
    {
        std::cout << "Треугольник невалиден." << std::endl;
    }
}

bool HandleCommand(Triangle &triangle, std::string const &command)
{
    if (command == COMMAND_INCREASE_ANGLE_A)
    {
        return IncreaseAngleA(triangle);
    }
    else if (command == COMMAND_INCREASE_ANGLE_B)
    {
        return IncreaseAngleB(triangle);
    }
    else if (command == COMMAND_DECREASE_ANGLE_A)
    {
        return DecreaseAngleA(triangle);
    }
    else if (command == COMMAND_DECREASE_ANGLE_B)
    {
        return DecreaseAngleB(triangle);
    }
    else if (command == COMMAND_PRINT_HEIGHTS)
    {
        return PrintTriangleHeights(triangle);
    }
    else if (command == COMMAND_PRINT_SIDES)
    {
        return PrintTriangleSides(triangle);
    }
    else if (command == COMMAND_VALIDATE)
    {
        PrintTriangleInfo(triangle);
        ValidateTriangle(triangle);
        return true;
    }
    else if (command == COMMAND_HELP)
    {
        PrintHelp();
        return true;
    }

    return false;
}

bool ReadTriangleSide(Triangle &triangle)
{
    std::cout << "Введите длину стороны треугольника." << std::endl;
    std::string sideStr;

    if (!getline(std::cin, sideStr))
    {
        return false;
    }

    try
    {
        int side = std::stoi(sideStr);
        if (!triangle.SetSide(side))
        {
            return false;
        }

        PrintTriangleInfo(triangle);
    }
    catch (const std::exception &e)
    {
        return false;
    }

    return true;
}

int main(int argc, char const *argv[])
{
    Triangle triangle = Triangle();

    if (!ReadTriangleSide(triangle))
    {
        return 1;
    }

    PrintHelp();

    while (!std::cin.eof() && !std::cin.fail())
    {
        std::cout << "Введите команду:" << std::endl;
        std::string commandLine;

        if (!getline(std::cin, commandLine) || (commandLine == COMMAND_EXIT))
        {
            break;
        }

        if (!HandleCommand(triangle, commandLine))
        {
            std::cout << "Ошибка ввода данных. Используйте команду " << COMMAND_HELP
                      << ", чтобы узнать возможные команды" << std::endl;
        }
    }

    return 0;
}