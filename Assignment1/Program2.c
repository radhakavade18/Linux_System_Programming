// PS - Write a program which except file name from user and open that file in a specific mode

#include<stdio.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    int fd = 0;
    char fName[50]; 

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
    return 0;
}