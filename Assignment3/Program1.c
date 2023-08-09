// PS - Write a program which accepts 2 file names from user and copy the content of an existing file into newly created file

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    int fdSource = 0;
    int fdDest = 0;
    int Ret = 0;
    char Buffer[BLOCKSIZE];

    if(argc != 3)
    {
        printf("Insufficient arguments \n");
        printf("Usage : Name_Of_Executable Name_Of_First_File Name_Of_Second_File \n");
        return -1;
    }

    fdSource = open(argv[1], O_RDONLY);
    if(fdSource == -1)
    {
        printf("Unable to open file \n");
        return -1;
    }

    fdDest = creat(argv[2], 0777);
    if(fdDest == -1)
    {
        printf("Unable to create file \n");
        return -1;
    }

    while ((Ret = read(fdSource, Buffer, BLOCKSIZE)) != 0)
    {
        write(fdDest, Buffer, Ret);
    }
    
    close(fdSource);
    close(fdDest);

    return 0;
}