// PS - Write a program which accepts directory name from user and combine all contents of file
// from that directory into one file named as allCombine.txt

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    int fd_new = 0;
    int fd_dirFile = 0;
    struct dirent *entry = NULL;
    char name[30];
    char Buffer[1024] = {'\0'};
    int Ret = 0;
    struct stat sobj;

    dp = opendir(argv[1]);

    if (dp == NULL)
    {
        printf("Unable to open directory \n");
        return -1;
    }

    fd_new = creat("allCombine.txt", 0777);
    if (fd_new == -1)
    {
        printf("Unable to create file \n");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        sprintf(name, "%s/%s", argv[1], entry->d_name);
        stat(name, &sobj);

        if (S_ISREG(sobj.st_mode))
        {
            fd_dirFile = open(name, O_RDONLY);
            while ((Ret = read(fd_dirFile, Buffer, sizeof(Buffer))) != 0)
            {
                write(fd_new, Buffer, Ret);
            }
        }
    }

    closedir(dp);
    close(fd_new);
    close(fd_dirFile);

    return 0;
}