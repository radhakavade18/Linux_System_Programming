// PS - Write a program which is used to demonstrate concept of I/O redirection

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int No1 = 0, No2 = 0, Ans = 0;

    printf("Enter 1st number \n");
    scanf("%d", &No1);

    printf("Enter 2nd number \n");
    scanf("%d", &No2);

    Ans = No1 + No2;

    printf("Addition is %d \n", Ans);

    return 0;
}