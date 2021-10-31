#include <iostream>

#define Conn(x, y) (x##y)           //##：连接作用#A#@
#define ToStr(x)   (#x)             //#：转化为字符串





int main()
{
    int a = 1;
    std::cout << ToStr(a) << std::endl;


    return 0;
}






