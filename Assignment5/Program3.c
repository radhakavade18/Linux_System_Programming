// PS - Write a program which accepts directory name from user and write information of all regular
// file in and then read the content from that file

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

struct fileInfo
{
    char fName[50];
    int fSize;
    int Links;
    int ino;
    int sysNum;
    int blockNum;
};

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    char path[50] = {'\0'};
    struct dirent *entry = NULL;
    struct stat sobj;
    int fd = 0;
    char Buffer[1024] = {'\0'};
    struct fileInfo fobj;
    int Ret = 0;

    dp = opendir(argv[1]);

    if (dp == NULL)
    {
        printf("Unable to open directory \n");
        return -1;
    }

    fd = creat(argv[2], 0777);
    if (fd == -1)
    {
        printf("Unable to create the file \n");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        sprintf(path, "%s/%s", argv[1], entry->d_name);
        stat(path, &sobj);

        if (S_ISREG(sobj.st_mode))
        {
            strcpy(fobj.fName, path);
            fobj.fSize = sobj.st_size;
            fobj.Links = sobj.st_nlink;
            fobj.ino = sobj.st_ino;
            fobj.sysNum = sobj.st_dev;
            fobj.blockNum = sobj.st_blocks;

            write(fd, &fobj, sizeof(fobj));

            // printf("File name : %s \n", fobj.fName);
            // printf("File size : %d \n", fobj.fSize);
            // printf("Number of links : %d \n", fobj.Links);
            // printf("Inode Number : %d \n", fobj.ino);
            // printf("File system number : %d \n", fobj.sysNum);
            // printf("Number of blocks %d \n", fobj.blockNum);
        }
    }

    while ((Ret = read(fd, Buffer, sizeof(Buffer))) != 0)
    {
        printf("Data from file is : \n");
        write(1, Buffer, Ret);
    }

    closedir(dp);
    close(fd);
    return 0;
}