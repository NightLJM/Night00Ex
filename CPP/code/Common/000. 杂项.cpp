#include <iostream>

using namespace std;


int main()
{
    auto address = 0x04030201;
    char *pAddress = (char*)(&address);

    cout << (int)pAddress[0] << (int)pAddress[1] << (int)pAddress[2] << (int)pAddress[3] << endl;

    return 0;
}

