#include <QtCore/QList>
#include <QtCore/QSet>
#include <QtCore/QVector>
#include <QtCore/QStringList>
#include <QtCore/QFlags>
#include <iostream>

/*
 * g++ 005.QFlags_Test.cpp -o a.out -L$QTDIR/lib -lQt5Core -fPIC
 */

enum MyFlag
{
    Flag0 = 0x00,
    Flag1 = 0x01,
    Flag2 = 0x02,
    Flag3 = 0x04
};

Q_DECLARE_FLAGS(MyFlags, MyFlag);


int main()
{
    //Flags转int
    {
        MyFlags flags1(MyFlag::Flag1);
        MyFlags flags2(MyFlag::Flag2);
        MyFlags flags3;
        flags3 = (MyFlags)0x03;
        std::cout << int(flags1 | flags2) << std::endl;
        std::cout << flags3.testFlag(Flag0) << " " << flags3.testFlag(Flag1) << " " << flags3.testFlag(Flag2) << " " << flags3.testFlag(Flag3) << std::endl;
    }


    return 0;
}