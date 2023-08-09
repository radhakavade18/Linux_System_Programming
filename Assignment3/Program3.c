// PS - Write a program which accepts 2 directory name from user and move all files from source directory
// to destination directory

#include<stdio.h>
#include<fcntl.h>
#include<dirent.h>
#include<unistd.h>
#include<string.h>

#define BLOCKSIZE 1024

int main(int argc, char *argv[])
{
    DIR *source_dp = NULL;
    DIR *dest_dp = NULL;
    int fd_creat = 0;
    int fd_open = 0;
    char path[50];
    int Ret = 0;
    char Buffer[BLOCKSIZE];

    struct dirent * entry = NULL;

    source_dp = opendir(argv[1]);
    dest_dp = opendir(argv[2]);

    if(source_dp == NULL || dest_dp == NULL)
    {
        printf("Unable to open directory \n");
        return -1;
    }

    while ((entry = readdir(source_dp)) != NULL)
    {
        sprintf(path, "%s/%s", argv[2], entry->d_name);
        fd_creat = creat(path, 0777);
        
        fd_open = open(path, O_RDWR);
        if(fd_open == -1)
        {
            printf("Unable to open the file \n");
        }
        Ret = read(fd_creat, Buffer, sizeof(Buffer));
        write(fd_open, Buffer, Ret);
    }
    
    closedir(source_dp);
    closedir(dest_dp);
    close(fd_open);
    close(fd_creat);
    
    return 0;
}