// PS - Write a program which except directory name from user and print all file names and its types from that directory

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    char path[256] = {'\0'};
    struct stat sobj;

    if(argc != 2)
    {
        printf("Insufficient arguments \n");
        printf("USAGE : Name_Of_Executable Name_Of_Directory");
        return -1;
    }

    DIR *dp = NULL;
    struct dirent *entry = NULL;

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory \n");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        sprintf(path, "%s/%s", argv[1], entry->d_name);     // create file path for stat function

        stat(path, &sobj);
        printf("%s \t", entry->d_name);                        // print file name

        if(S_ISREG(sobj.st_mode))
        {
            printf("Its a regular file \n");
        }
        else if(S_ISDIR(sobj.st_mode))
        {
            printf("Its a directory file \n");
        }
        else if(S_ISLNK(sobj.st_mode))
        {
            printf("Its a Sysmbolic link \n");
        }
    }
    
    closedir(dp);

    return 0;
}