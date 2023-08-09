// PS - Write a program which accepts directory name from user and create hole in file if size is less than
// 1 kb & if it is greater than 1 kb then truncate the remaining data

#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<sys/stat.h>

#define BLOCK 1024

int main(int argc, char * argv[])
{
    DIR *dp = NULL;
    struct dirent * entry = NULL;
    struct stat sobj;
    char path[50] = {'\0'};

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open the directory \n");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        sprintf(path, "%s/%s", argv[1], entry->d_name);
        stat(path, &sobj);

        if(S_ISREG(sobj.st_mode))
        {
            if(sobj.st_size < BLOCK)
            {
                printf("File size is %d \n", sobj.st_size);
            }
        }
    }
    

    return 0;
}