#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

using namespace std;

void sig_alrm(int signo);
void sig_chld(int signo);
static bool g_bChildFinish = false;

int main()
{
    //signal(SIGALRM, sig_alrm);
    signal(SIGALRM, SIG_IGN);
    signal(SIGCHLD, sig_chld);

    int pid = -1;

    if ((pid = fork()) < 0)
    {
        cout << "fork error" <<endl;
    }
    else if (pid == 0)
    {
        alarm(2);
    }
    else
    {
        cout << "fork success, child pid = " << pid << endl;
    }
    

    while (!g_bChildFinish)
    {
        
    }

    cout << "process finsh, pid = " << getpid() << endl;
    return 0;
}


void sig_alrm(int signo)
{
    cout << "SIGALRM received" << endl;
}

void sig_chld(int signo)
{

    int status;
    int pid = wait(&status);

    g_bChildFinish = true;

    cout << "SIGCHLD received: pid = " << pid << endl;
}