#include "../../include/ToString.h"
#include <iostream>

using namespace night00;
using namespace std;

int main()
{
    list<int> ltest = {1, 2, 3, 4, 5, 6, 7};
    set<int> stest = {1, 2, 4, 3, 5, 6, 7};
    float dtest = 1.305f;

    cout << toString(ltest) << endl;
    cout << toString(stest) << endl;
    cout << toString(dtest) << endl;
    return 0;
}