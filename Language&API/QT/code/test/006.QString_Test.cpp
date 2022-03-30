#include <iostream>
#include <QtCore/QString>

/*
 * g++ 006.QString_Test.cpp -o a.out -L$QTDIR/lib -lQt5Core -fPIC
*/

int main()
{
    //数字转字符串
    {
        //sprintf用来格式化字符串；数字转字符串可用QString::number
        QString s = QString().sprintf("%02d", 2);
        std::cout << s.toStdString() << std::endl;
    }




    return 0;
}