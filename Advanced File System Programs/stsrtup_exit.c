//Program to demostrate startup and exit using #pragma.
#include<stdio.h>
void fun();
void sun() ;

#pragma startup fun     // call fun function before main function - only function name not function call ()
#pragma exit sun        // call sun after main

int main()
{
printf("\nIn main");
return 0;
}

void fun()
{
printf("\nIn fun");
}

void sun()
{
printf("\nIn sun");
}
