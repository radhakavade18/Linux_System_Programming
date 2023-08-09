// PS - Write a program which accepts 2 file names from user and check whether the content of both the files are same or not

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Insufficient parameter \n");
        printf("USAGE : Name_Of_Executable Name_Of_First_File Name_Of_Second_File");
        return -1;
    }
    struct stat sobj1;
    struct stat sobj2;
    int fd1 = 0;
    int fd2 = 0;
    int Ret = 0;
    char Buffer1[1024] = {'\0'};
    char Buffer2[1024] = {'\0'};
    int check = 0;

    stat(argv[1], &sobj1);
    stat(argv[2], &sobj2);

    if(sobj1.st_size == sobj2.st_size)
    {
        fd1 = open(argv[1], O_RDONLY);
        if(fd1 == -1)
        {
            printf("Unable to open file \n");
            return -1;
        }
        fd2 = open(argv[2], O_RDONLY);
        if(fd2 == -1)
        {
            printf("Unable to open file \n");
            return -1;
        }
        while ((Ret = read(fd1, Buffer1, sizeof(Buffer1))) != 0)  
        {
            Ret = read(fd2, Buffer2, sizeof(Buffer2));
            check = strcmp(Buffer1, Buffer2);
            if(check == 0)
            {
                printf("Files are same \n");
            }
        }
    }
    else
    {
        printf("Files are different \n");
    }

    close(fd1);
    close(fd2);
    
    return 0;
}