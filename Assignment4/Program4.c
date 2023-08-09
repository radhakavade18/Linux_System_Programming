// PS - Write a program which accept directory name from user and copy first 10 bytes from all regular files
// into newly created file named as Demo.txt

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Insufficient parameter \n");
        printf("USAGE : Name_Of_Executable Name_Of_Directory");
        return -1;
    }

    int fd = 0;
    DIR *dp = NULL;
    struct dirent * entry = NULL;
    int Ret = 0;
    char Buffer[10] = {'\0'};
    char path[50] = {'\0'};
    int fd_dirFile = 0;

    dp = opendir(argv[1]);
    fd = creat("Demo.txt", 0777);

    fd = open("Demo.txt", O_RDWR);
    if(fd == -1)
    {
        printf("Unable to open the file \n");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        sprintf(path, "%s/%s", argv[1], entry->d_name);
        fd_dirFile = open(path, O_RDWR);

        Ret = read(fd_dirFile, Buffer, 10);
        write(fd, Buffer, 10);
    }
    closedir(dp);

    return 0;
}