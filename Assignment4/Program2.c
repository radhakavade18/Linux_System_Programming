// PS - Write a program which except directory name from user and create new directory

#include<stdio.h>
#include<fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    char dirName[50];
    int Ret = 0;

    printf("Enter directory name that you want to create \n");
    scanf("%s", dirName);
    
    Ret = mkdir(dirName, 0777);

    if(Ret == 0)
    {
        printf("Directory created successfully \n");
    }
    else
    {
        printf("Unable to create directory \n");
    }
    
    return 0;
}