#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

static void sig_cld(int);

int main()
{
    pid_t pid;

    if (signal(SIGCLD, sig_cld) == SIG_ERR)
    {
        std::cout << "signal error" << std::endl;
    }
    if ((pid = fork()) < 0)
    {
        std::cout << "fork error" << std::endl;
    }
    else if(pid == 0)
    {
        std::cout << "child pid = " << getpid() << std::endl;

        sleep(2);
        _exit(0);
    }
    else
    {
        std::cout << "parent pid = " << getpid() << std::endl;
    }
    

    pause();
    std::cout << "after pause" << std::endl;
    return 0;
}

void sig_cld(int signo)
{
    pid_t pid;
    int status;

    std::cout << "SIGCLD received" << std::endl;

    if (signal(SIGCLD, sig_cld) == SIG_ERR)
    {
        std::cout << "signal error" << std::endl;
    }

    if ((pid = wait(&status)) < 0)
    {
        std::cout << "wait error" << std::endl;
    }

    std::cout << "pid = " << pid << std::endl;
}
