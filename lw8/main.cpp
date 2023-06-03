#include <iostream>
#include <iterator>

class Mammal
{
public:
    virtual std::string info() const = 0;
};

class Animal : public Mammal
{
};

class Cow : public Animal
{
    std::string info() const override
    {
        return "Hello, I am a big cow!";
    }
};

class Dog : public Animal
{
    std::string info() const override
    {
        return "Woof-woof, I am a dog.";
    }
};

class Human : public Mammal
{
    std::string info() const override
    {
        return "Hi, my name is Angelina, I am a human =)";
    }
};

int main(int argc, char const *argv[])
{
    Mammal *mammals[6];
    mammals[0] = new Cow();
    mammals[1] = new Dog();
    mammals[2] = new Cow();
    mammals[3] = new Human();
    mammals[4] = new Dog();
    mammals[5] = new Human();

    int itemsCount = sizeof(mammals) / sizeof(mammals[0]);
    for (size_t i = 0; i < itemsCount; i++)
    {
        std::cout << std::to_string(i) << std::endl;
        std::cout << mammals[i]->info() << std::endl;
    }

    return 0;
}