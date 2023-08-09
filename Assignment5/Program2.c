// PS - Write a program which accepts file name from user which contain information about the employee,
// We have to read the content of that file

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#pragma pack(1)

struct Employee
{
    int Rollno;
    char Sname[20];
    float Marks;
    int Age;
};

int main(int argc, char *argv[])
{
    struct Employee sobj;
    char fname[20];
    int fd = 0;

    printf("Enter the file name \n");
    scanf("%s", fname);

    fd = open(fname, O_RDONLY);

    if(fd == -1)
    {
        printf("Unable to open file \n");
        return -1;
    }

    read(fd, &sobj, sizeof(sobj));

    printf("Roll number : %d \n", sobj.Rollno);
    printf("Name : %s \n", sobj.Sname);
    printf("Marks : %f \n", sobj.Marks);
    printf("Age : %d \n", sobj.Age);

    close(fd);

    return 0;
}