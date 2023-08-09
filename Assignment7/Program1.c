// PS - create shared library, that library should be loaded at run time by the other program
// that library should contain arithmatic operations like addition, substraction, Division, Multiplication

#include<stdio.h>
#include<stdlib.h>
#include<dlfcn.h>

int main()
{
    void *ptr = NULL;
    int Ret = 0;
    float fRet = 0.0f;

    int (*fptr)(int, int);
    float (*fptr1)(int, int);

    ptr = dlopen("library.so", RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("Unable to load library \n");
        return -1;
    }

    fptr = dlsym(ptr, "Addition");

    if(fptr == NULL)
    {
        printf("Unable to load the address of function \n");
        return -1;
    }

    Ret = fptr(10, 11);

    printf("Addition is %d \n", Ret);

    fptr = dlsym(ptr, "Substraction");

    if(fptr == NULL)
    {
        printf("Unable to load the address of function \n");
        return -1;
    }

    Ret = fptr(10, 11);

    printf("Substraction is %d \n", Ret);

    fptr = dlsym(ptr, "Multiplication");

    if(fptr == NULL)
    {
        printf("Unable to load the address of function \n");
        return -1;
    }

    Ret = fptr(10, 11);

    printf("Multiplication is %d \n", Ret);

    fptr1 = dlsym(ptr, "Devision");

    if(fptr1 == NULL)
    {
        printf("Unable to load the address of function \n");
        return -1;
    }

    fRet = fptr1(10, 2);

    printf("Division is %f \n", fRet);

    return 0;
}