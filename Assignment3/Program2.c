// PS - Write a program which accept directory name and file name from user and check whether 
// that file is present in that directory or not

#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<string.h>

int main(int argc, char *argv[])
{
    char dirName[50] = {'\0'};
    char fileName[50] = {'\0'};

    DIR *dp = NULL;
    struct dirent *entry = NULL;

    printf("Enter directory name \n");
    scanf("%s", dirName);

    printf("Enter file name \n");
    scanf("%s", fileName);

    dp = opendir(dirName);
    if(dp == NULL)
    {
        printf("Unable to open directory \n");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        if(strcmp(entry->d_name, fileName) == 0)
        {
            printf("File is present \n");
        }
    }

    closedir(dp);

    return 0;
}