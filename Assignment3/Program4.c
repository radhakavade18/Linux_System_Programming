// PS - Write a program which accepts directory name form user and delete all empty files from that directory

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char path[50] = {'\0'};
    struct stat sobj;

    dp = opendir(argv[1]);
    if (dp == NULL)
    {
        printf("Unable to open the directory file \n");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        sprintf(path, "%s/%s", argv[1], entry->d_name);

        stat(path, &sobj);
        printf("%d \n", sobj.st_size);

        if (sobj.st_size == 0)
        {
            remove(path);
        }
    }

    closedir(dp);

    return 0;
}