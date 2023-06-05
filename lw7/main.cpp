#include <iostream>

// Автомобиль, поезд, транспортное средство, экспресс

// Транспортное средство
class Vehicle
{
public:
    ~Vehicle(){};

    virtual std::string GetInfo() const
    {
        return "Vehicle";
    }
};

// Автомобиль
class Car : public Vehicle
{
public:
    Car(std::string const &model) : m_model(model) {}

    std::string GetInfo() const override
    {
        return "Car (" + m_model + ") -> " + Vehicle::GetInfo();
    }

private:
    std::string m_model;
};

// Поезд
class Train : Vehicle
{
public:
    Train(std::string destination) : m_destination(destination) {}
    ~Train(){};

    std::string GetInfo() const override
    {
        return "Train to " + m_destination + " -> " + Vehicle::GetInfo();
    }

private:
    std::string m_destination;
};

// Express
class Express : Train
{
public:
    Express(std::string const &name, std::string const &destination) : m_name(name), Train(destination) {}

    std::string GetInfo() const override
    {
        return "Express " + m_name + " -> " + Train::GetInfo();
    }

private:
    std::string m_name;
};

int main(int argc, char const *argv[])
{
    Car car = Car("Toyota Camry V50, Silver");
    Express express = Express("Lastochka", "Bussan");

    std::cout << "We have two vehicles:" << std::endl;
    std::cout << car.GetInfo() << std::endl;
    std::cout << express.GetInfo() << std::endl;

    return 0;
}
