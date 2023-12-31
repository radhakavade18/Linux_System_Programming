// This program demonstates creation of symbolic link means soft link.
// A symbolic link is a special type of file whose contents are a string
// that is the pathname another file, the file to which the link refers.
// Symbolic  links  are  files  that act as pointers to other files. But in case of hard link
// new name of the file gets added in directory with the same inode number.
// In user level symbolic links are called as shortcuts.

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int fd = 0, ret = 0;
	char buff[30];

	ret = symlink("new.txt", "symlink.txt"); 	// Existing file, newly created symbolic link
	if (ret == -1)
	{
		printf("Unable to create symbolic link\n");
		return -1;
	}

	// If we create symbolic link for such a file which is not existing
	// then that type of link is called as dangling link.
	// (Just like a dangling pointer, which points to nothing)

	// As symbolic link contains path of another file we can read this file by
	// using readlink system call.

	ret = readlink("symlink.txt", buff, sizeof(buff));
	if (ret == 0)
	{
		printf("Unable to retrive ");
	}

	printf("Contents inside the sybolic link are\n%s", buff);

	// opening a symbolic link
	fd = open("symlink.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Unable to open the file\n");
		return -1;
	}

	memset(buff, 0, sizeof(buff));

	// When we read teh symbolic link we get data inside the original file.

	ret = read(fd, buff, sizeof(buff));
	if (ret == 0)
	{
		printf("Unable to read contents\n");
		return -1;
	}

	printf("\nContents inside the sybolic link are : %s\n", buff);

	return 0;
}
