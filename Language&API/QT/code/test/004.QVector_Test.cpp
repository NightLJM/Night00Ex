#include <QtCore/QList>
#include <QtCore/QSet>
#include <QtCore/QVector>
#include <QtCore/QStringList>
#include <iostream>

/*
 * g++ 004.QVector_Test.cpp -o a.out -L$QTDIR/lib -lQt5Core  -fPIC
 */

int main()
{
    //1. indexof测试
    {
        QVector<int> v;
        v << 1 << 2 << 3;
        int index = v.indexOf(4);
        std::cout << index << std::endl;
    }


    return 0;
}