// PS - Write a program which writes structure in file. Structure should contain information about student

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#pragma pack(1)

struct Student
{
    int Rollno;
    char Sname[20];
    float Marks;
    int Age;
};

int main(int argc, char *argv[])
{
    struct Student sobj;
    char fname[20];
    int fd = 0;

    sobj.Rollno = 11;
    strcpy(sobj.Sname, "Radha");
    sobj.Marks = 88.98;
    sobj.Age = 27;

    printf("Enter the file name \n");
    scanf("%s", fname);

    fd = creat(fname, 0777);

    if(fd == -1)
    {
        printf("Unable to create file \n");
        return -1;
    }

    write(fd, &sobj, sizeof(sobj));

    return 0;
}