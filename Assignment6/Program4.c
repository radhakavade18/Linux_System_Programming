// PS - Write a program which accepts directory name from user and delete all such a files whose size
// is greater than 100 bytes

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent * entry = NULL;
    char path[50];
    struct stat sobj;

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory \n");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        sprintf(path, "%s/%s", argv[1], entry->d_name);
        stat(path, &sobj);

        if(S_ISREG(sobj.st_mode))
        {
            if(sobj.st_size > 100)
            {
                remove(path);
            }
        }
    }
    
    closedir(dp);
    
    return 0;
}