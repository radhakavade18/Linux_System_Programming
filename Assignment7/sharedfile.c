#include"sharedfile.h"
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>      // required for directory
#include<string.h>
#include<sys/dir.h>     // required for directory
#include<sys/stat.h>

int Addition(int No1, int No2)
{
    int Ans = 0;
    Ans = No1 + No2;
    return Ans;
}

int Substraction(int No1, int No2)
{
    int Ans = 0;
    Ans = No1 - No2;
    return Ans;
}

int Multiplication(int No1, int No2)
{
    int Ans = 0;
    Ans = No1 * No2;
    return Ans;
}

float Devision(int No1, int No2)
{
    int Ans = 0;
    Ans = No1 / No2;
    return Ans;
}

void CompareFileContent(char str1[], char str2[])
{
    int fd1 = 0, fd2 = 0;
    struct stat sobj1,sobj2;
    char Buffer1[1024];
    char Buffer2[1024];
    int Ret = 0;

    fd1 = open(str1, O_RDWR); // opened file in the read and write mode

    printf("File opened successfully with fd %d\n", fd1);

    fd2 = open(str2, O_RDWR); // opened file in the read and write mode

    printf("File opened successfully with fd %d\n", fd2);

    fstat(fd1, &sobj1);
    fstat(fd1, &sobj2);

    if(sobj1.st_size != sobj2.st_size)
    {
        printf("File sizes are different so the content is not same \n");
    }

    while ((Ret = read(fd1, Buffer1, sizeof(Buffer1))) != 0)
    {
        Ret = read(fd2, Buffer2, sizeof(Buffer1));
        if(memcmp(Buffer1, Buffer2, Ret) != 0)
        {
            break;
        }
    }

    if(Ret == 0)
    {
        printf("Both files are idential \n");
    }
    else
    {
        printf("Both files are different \n");
    }

    close(fd1);
    close(fd2);
}