// PS - Write a program which except file name and mode and that program check whether our
// process can access that file in accepted mode or not.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    char fName[50]; 
    int Ret = 0;

    printf("Enter file name that you want to open \n");
    scanf("%s", fName);

    fd = open(fName, O_RDWR);       // opened file in the read and write mode

    if(fd == -1)
    {
        printf("Unable to open the file \n");
        return -1;
    }
    else
    {
        printf("File opened successfully with fd %d\n", fd);
    }

    // to used to check whether the calling program has access to a specified file
    // return 0 if yes
    // return -1 if no
    Ret = access(fName, O_RDWR);

    if(Ret == 0)
    {
        printf("Successfully accessed the file \n");
    }
    else
    {
        printf("Not having permissions to access the file \n");
    }

    return 0;
}