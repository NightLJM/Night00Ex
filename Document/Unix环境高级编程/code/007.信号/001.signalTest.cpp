#include <signal.h>
#include <iostream>
#include <string>

using namespace std;

void sig_fun1(int nSigNo)
{
    switch(nSigNo)
    {
    case SIGUSR1:
        cout << "sig_fun1:accept signal SIGUSR1" << endl;
        break;
    case SIGUSR2:
        cout << "sig_fun1:accept signal SIGUSR2" <<endl;
        break;
    default:
        cout << "sig_fun1:accept signal No = " << nSigNo << endl;
        break;
    }
}

void sig_fun2(int nSigNo)
{
    switch(nSigNo)
    {
    case SIGUSR1:
        cout << "sig_fun2:accept signal SIGUSR1" << endl;
        break;
    case SIGUSR2:
        cout << "sig_fun2:accept signal SIGUSR2" <<endl;
        break;
    default:
        cout << "sig_fun2:accept signal No = " << nSigNo << endl;
        break;
    }
}

int main()
{
    //一个信号只能连一个函数
    if (signal(SIGUSR1, sig_fun1) == SIG_ERR)
    {
        cout << "sig1_fun1 connect err!" << endl;
    }
    if (signal(SIGUSR2, sig_fun1) == SIG_ERR)
    {
        cout << "sig2_fun1 connect err!" << endl;
    }

    if (signal(SIGUSR1, sig_fun2) == SIG_ERR)
    {
        cout << "sig1_fun2 connect err!" << endl;
    }
    if (signal(SIGUSR2, sig_fun2) == SIG_ERR)
    {
        cout << "sig2_fun2 connect err!" << endl;
    }

    while(true)
    {
        ;
    }

    return 0;
}