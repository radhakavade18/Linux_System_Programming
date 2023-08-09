// PS - Write a program which accept directory name from user and print name of such a file having largest size

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    char path[256];
    struct dirent * entry = NULL;
    struct stat sobj;

    int iMax = 0;
    char maxFile[50] = {'\0'};

    if(argc != 2)
    {
        printf("Insufficient arguments \n");
        printf("USAGE : Name_Of_Executable Name_Of_Directory");
        return -1;
    }

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open the directory file \n");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        sprintf(path, "%s/%s", argv[1], entry->d_name);
        stat(path, &sobj);

        if(S_ISREG(sobj.st_mode))
        {
            if(iMax < sobj.st_size)
            {
                iMax = sobj.st_size;
                strcpy(maxFile, path);
            }
        }
    }
    
    printf("Name of largest file is %s with size of bytes %d \n", maxFile, iMax);

    closedir(dp);

    return 0;
}