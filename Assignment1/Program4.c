// PS - Write a program which except file name and on mode anf that program check whether our process can access that file
// in accepted mode or not.

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>        // need
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
    struct stat sobj;
    int fd = 0;

    if(argc != 2)
    {
        printf("Insufficient parameter \n");
        return -1;
    }

    stat(fd, &sobj);

    printf("File name : %s \n", argv[1]);
    printf("File size is : %lld \n", sobj.st_size);
    printf("File type and modes : %d \n", sobj.st_mode);
    printf("Inode number : %llu \n", sobj.st_ino);
    printf("Number of blocks allocated : %lld \n", sobj.st_blocks);
    printf("File system number %d \n", sobj.st_dev);

    return 0;
}