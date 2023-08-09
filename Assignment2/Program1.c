// PS - Write a program which except file name from user and read all the data from file

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fd = 0;
    char Buffer[BLOCKSIZE];
    int iRet = 0;

    if(argc != 2)
    {
        printf("Insufficient Parameters \n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open the file \n");
        return -1;
    }

    while ((iRet = read(fd, Buffer, sizeof(Buffer))) != 0)
    {
        write(1, Buffer, iRet);
    }
    
    close(fd);

    return 0;
}