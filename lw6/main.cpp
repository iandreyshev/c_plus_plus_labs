#include <iostream>

class B1
{
public:
    std::string data;

    B1() : data("B1") {}
    explicit B1(const std::string &data) : data(data + "-->B1") {}

    virtual void show()
    {
        std::cout << data << ".show()" << std::endl;
    }
};

class B2
{
public:
    std::string data;

    B2() : data("B2") {}

    explicit B2(const std::string &data) : data(data + "-->B2") {}

    virtual void show()
    {
        std::cout << data << ".show()" << std::endl;
    }
};

class B3
{
public:
    std::string data;

    B3() : data("B3") {}

    explicit B3(const std::string &data) : data(data + "-->B3") {}

    virtual void show()
    {
        std::cout << data << ".show()" << std::endl;
    }
};

class D1 : private B1, public B2, protected B3
{
public:
    explicit D1(const std::string &data) : B1(data + "-->D1"), B2(data + "-->D1"), B3(data + "-->D1") {}

    D1() : B1("D1"), B2("D1"), B3("D1") {}

    void show() override
    {
        B1::show();
        B2::show();
        B3::show();
    }
};

class D3 : public B3
{
public:
    explicit D3(const std::string &data) : B3(data + "-->D3") {}

    D3() : B3("D3") {}

    void show() override
    {
        B3::show();
    }
};

class D2 : public D1, private D3
{
public:
    explicit D2(const std::string &data) : D1(data + "-->D2"), D3(data + "-->D2") {}

    D2() : D1("D2"), D3("D2") {}

    void show() override
    {
        D1::show();
        D3::show();
    }
};

class D4 : protected D2
{
public:
    D4() : D2("D4") {}

    void show() override
    {
        D2::show();
    }
};

int main(int argc, char const *argv[])
{

    B1 b1;
    b1.show();
    std::cout << std::endl;

    B2 b2;
    b2.show();
    std::cout << std::endl;

    B3 b3;
    b3.show();
    std::cout << std::endl;

    D1 d1;
    d1.show();
    std::cout << std::endl;

    D2 d2;
    d2.show();
    std::cout << std::endl;

    D3 d3;
    d3.show();
    std::cout << std::endl;

    D4 d4;
    d4.show();

    return 0;
}