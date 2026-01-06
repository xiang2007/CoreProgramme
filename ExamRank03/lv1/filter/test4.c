#define _GNU_SOURCE
#ifndef BUF_SIZE
# define BUF_SIZE 10
#endif

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

char	*strjoin(char *s1, char *s2)
{
	int	size1, size2;
	char	*res;

	size1 = (s1) ? strlen(s1) : 0;
	size2 = (s2) ? strlen(s2) : 0;
	res = malloc(size1 + size2 + 1);
	if (!res)
		return (0);
	if (s1) memcpy(res, s1, size1);
	if (s2) memcpy(res + size1, s2, size2);
	res[size1 + size2] = '\0';
	free(s1);
	return (res);
}

void	errmsg()
{
	perror("Error\n");
	return ;
}

int	main(int ac, char **av)
{
	char	buffer[BUF_SIZE + 1];
	char	*res;
	size_t		n;
	ssize_t		r;

	if (ac != 2)
		return (errmsg(), 1);
	n = strlen(av[1]);
	while ((r = read(0, buffer, BUF_SIZE)) > 0)
	{
		buffer[r] = '\0';
		if (!(res = strjoin(res, buffer)))
			return (errmsg(), 1);
	}
	for (char *p = res; n && (p = memmem(p, strlen(p), av[1], n)); p += n)
		memset(p, '*', n);
	printf("%s\n", res);
	free(res);
	return (0);
}


Assignment name   : get_next_line
Expected files    : get_next_line.c get_next_line.h
Allowed functions : read, free, malloc
--------------------------------------------------------------------------------

Write a function named get_next_line which prototype should be:
char    *get_next_line(int fd);

"Your function must return a line that has been read from the file descriptor
passed as parameter.

What we call a "line that has been read" is a succession of 0 to n characters
that end with '\n' (ascii code 0x0a) or with End Of File (EOF).

The line should be returned including the '\n' in case there is one at the end
of the line that has been read.

When you've reached the EOF, you must store the current buffer in a char * and
return it. If the buffer is empty you must return NULL.

In case of error return NULL.

In case of not returning NULL, the pointer should be free-able.

Your program will be compiled with the flag -D BUFFER_SIZE=xx, which has to be
used as the buffer size for the read calls in your functions.

Your function must be memory leak free.

When you've reached the EOF, your function should keep 0 memory allocated with
malloc except the line that has been returned.

Calling your function get_next_line in a loop will therefore allow you to read
the text available on a file descriptor one line at a time until the end of the
text, no matter the size of either the text or one of its lines.

Make sure that your function behaves well when it reads from a file, from the
standard output, from a redirection etc.

No call to another function will be done on the file descriptor between 2 calls
of get_next_line.

Finally we consider that get_next_line has an undefined behavior when reading
from a binary file.

You should use the test.sh to help you test your get_next_line."
