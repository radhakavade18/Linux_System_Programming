// PS - create shared library, that library should be loaded at run time by the other program
// that library should contain a function which accepts 2 file names from user and it will compare the contents of file.

#include<stdio.h>
#include<unistd.h>
#include<dlfcn.h>

int main(int argc, char *argv[])
{
    void *ptr = NULL;
    void(*fptr)(char *[], char *[]);

    ptr = dlopen(ptr, RTLD_LAZY);

    if(ptr == NULL)
    {
        printf("Unable to load library \n");
        return -1;
    }

    fptr = dlsym(ptr, "CompareFileContent");

    fptr(argv[1], argv[2]);

    return 0;
}