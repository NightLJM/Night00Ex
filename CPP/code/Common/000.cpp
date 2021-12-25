#include "gtest/gtest.h"
#include <QtCore/QString>
#include <QtCore/QStringList>
#include <string>
#include <iostream>
#include <QtCore/QMap>

template<typename T>
class B
{
class A
{
    friend class B<T>;
private:
    T m_p;
};

public:
    void fun()
    {
        std::cout << m_p.m_p << std::endl;
    }
private:
    A m_p;
};

int main()
{
    B<int> b;
    b.fun();
    B<char> bc;
    bc.fun();
    return 0;
}
