// This program demonstate use of stat function which gives information about the file.
// This program demonstate use of fstat function which gives information about the file.
// --------------------------------------------------------------------------------------------
// If we have a file name only we call stat function wich accepts file name as parameter
// If we have a file Descriptor then we can call fstat function which accepts FD as a parameter

#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
	int ret = 0;
	int fd = 0;
	struct stat fileStat;

	// stat function accept file name as a parameter
	ret = stat("file.txt", &fileStat);
	if (ret == -1)
	{
		printf("stat function fail\n");
		return -1;
	}

	printf("Calling function stat\n");
	printf("File Size : \t\t%d bytes\n", (int)fileStat.st_size);
	printf("Number of Links : \t%d\n", (int)fileStat.st_nlink);
	printf("File inode : \t\t%d\n", (int)fileStat.st_ino);
	printf("File system number: \t\t%d\n", (int)fileStat.st_dev);
	printf("Number of blocks allocated for file\t\t%d\n", (int)fileStat.st_blocks);

	printf("File Permissions: \t");
	// for directory
	printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
	// permission for user
	printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
	printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
	printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
	// permission for group
	printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
	printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
	printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
	// permission for others
	printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
	printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
	printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
	printf("\n\n");

	if (S_ISLNK(fileStat.st_mode))
	{
		printf("It is symbolic link\n");
	}
	else
	{
		printf("It is not symbolic link\n");
	}

	// If the file is already opened then we can call fstat function
	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Unable to open the file\n");
	}

	// fstat function accept file desx

	printf("Calling function fstat\n");
	memset(&fileStat, 0, sizeof(fileStat));
	ret = fstat(fd, &fileStat);
	if (ret == -1)
	{
		printf("Error in fstat");
	}

	printf("File Size : \t\t%d bytes\n", (int)fileStat.st_size);
	printf("Number of Links : \t%d\n", (int)fileStat.st_nlink);
	printf("File inode : \t\t%d\n", (int)fileStat.st_ino);

	return 0;
}
