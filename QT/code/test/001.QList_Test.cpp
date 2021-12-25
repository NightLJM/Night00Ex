#include <QtCore/QList>
#include <QtCore/QSet>
#include <QtCore/QStringList>
#include <iostream>


/*
 * g++ 001.QList_Test.cpp -o a.out -L$QTDIR/lib -lQt5Core  -fPIC
 */


template<class T>
void printT(const T& datas)
{
    for (auto iter = datas.begin(); iter != datas.end(); ++iter)
    {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
}

int main()
{
    //插入测试
    // {
    //     QList<int> insertTestList = {1, 2, 3};
    //     auto pos = insertTestList.begin();
    //     auto endIter = insertTestList.begin();
    //     for (int i = 0; i < 5; ++i)
    //     {
    //         pos = insertTestList.insert(pos, i) + 1;
    //     }
    //     printT(insertTestList);
    // }

    //QList转QSet测试
    // {
    //     QList<int> list1 = {1, 2, 3, 4};
    //     QSet<int> set1 = list1.toSet();
    //     for (auto iter = list1.begin(); iter != list1.end(); ++iter)
    //     {
    //         std::cout << *iter << " ";
    //     }
    //     std::cout << std::endl;
    // }

    QStringList s = {"123", "456"};
    int i = s.indexOf("789");
    std::cout << i << std::endl;

    return 0;
}
