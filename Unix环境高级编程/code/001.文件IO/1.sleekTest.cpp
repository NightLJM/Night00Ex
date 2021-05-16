#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
// #include <sys/types.h>
// #include <sys/stat.h>
#include <iostream>
using namespace std;

/*
 *测试lseek形成的空洞占不占文件大小
*/


static const char* pBuf1 = "abcdefg";
static const char* pBuf2 = "ABCDEFG";

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        perror("parameter counts error!");
        return 0;
    }

    int fd = -1;

    if ((fd = (open(argv[1], O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR))) == -1)
    {
        perror("open file fail!");
        return 0;
    }

    int size;

    if ((size = write(fd, pBuf1, 7)) != 7)
    {
        cout << size << endl;
        perror("write file error");
        return 0;
    }

    if (lseek(fd, atoi(argv[2]), SEEK_END) == -1)
    {
        perror("lseek error");
        return 0;
    }

    if (write(fd, pBuf2, 7) != 7)
    {
        perror("write file error");
        return 0;
    }
    
    return 0;
}

