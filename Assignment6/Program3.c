// PS - Write a program which accept directory name and file name from user and create file in that directory

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    int fd = 0;
    char path[50];

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory \n");
        return -1;
    }

    sprintf(path, "%s/%s", argv[1], argv[2]);

    fd = creat(path, 0777);
    if(fd == -1)
    {
        printf("Unable to create a new file \n");
        return -1;
    }

    close(fd);
    closedir(dp);

    return 0;
}