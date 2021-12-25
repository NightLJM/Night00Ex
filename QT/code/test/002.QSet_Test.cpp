#include <QtCore/QList>
#include <QtCore/QSet>
#include <QtCore/QStringList>
#include <iostream>
#include <set>

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

    //1. 删除测试
    {
        std::set<int> testSet = {1, 3, 4, 7, 6, 5};
        for (auto iter = testSet.begin(); iter != testSet.end();)
        {
            if (*iter == 3 || *iter == 4)
            {
                iter = testSet.erase(iter);
            }
            else
            {
                ++iter;
            }
        }
        printT(testSet);
    }

    return 0;
}