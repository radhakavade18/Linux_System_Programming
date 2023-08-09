// PS - Write a program which accepts file name and offset from user, remove all tha deta from that offset

#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

int main(int argc, char * argv[])
{
    int fd = 0;
    int pos = 0;

    fd = open(argv[1], O_RDONLY);
    if(fd == -1)
    {
        printf("Unable to open the file \n");
        return -1;
    }

    pos = lseek(fd, atoi(argv[2]), 0);

    printf("%d", pos);

    close(fd);

    return 0;
}