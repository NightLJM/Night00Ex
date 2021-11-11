#include "shared_ptr.h"
#include "gtest/gtest.h"

using namespace std;

class T
{
public:
    T() { cout << "construct func" << endl;}
    ~T() { cout << "disconstruct func" << endl;}
};

int main()
{
    {
        shared_ptr<T> ptr_t(new T());
        cout << "ptr_t will out" << endl; 
    }

    


    return 0;
}