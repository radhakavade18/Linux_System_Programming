// PS - Write a program which except file name and number of bytes from user and read that number of bytes from file

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    int Size = 0;
    int iRet = 0;
    char *Buffer = NULL;

    if(argc != 3)
    {
        printf("Insufficient parameter \n");
        return -1;
    }

    fd = open(argv[1], O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open file \n");
    }

    Size = atoi(argv[2]);

    Buffer = (char *)malloc(Size);

    iRet = read(fd, Buffer, atoi(argv[2]));

    if(iRet == 0)
    {
        printf("Unable to read data from file \n");
        return -1;
    }

    printf("Data from file is \n");
    write(1, Buffer, iRet);

    return 0;
}