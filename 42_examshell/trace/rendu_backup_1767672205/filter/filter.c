#define _GNU_SOURCE
#ifndef BUF_SIZE
# define BUF_SIZE 10
#endif

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	errmsg() { perror("Error\n"); }

char	*strjoin(char *s1, char *s2)
{
	int size1, size2 = 0;
	char	*temp;

	size1 = (s1) ? strlen(s1) : 0;
	size2 = (s2) ? strlen(s2) : 0;
	temp = malloc(size1 + size2 + 1);
	if (!temp)
		return (errmsg(), NULL);
	if (s1) memcpy(temp, s1, size1);
	if (s2) memcpy(temp + size1, s2, size2);
	temp[size1 + size2] = '\0';
	free(s1);
	return (temp);
}

int	main(int ac, char **av)
{
	char	buffer[BUF_SIZE + 1];
	char	*out = NULL;
	int		r;
	int		n;

	if (ac != 2)
		return (errmsg(), 1);
	n = strlen(av[1]);
	while ((r = read(0, buffer, BUF_SIZE)) > 0)
	{
		buffer[r] = 0;
		if (!(out = strjoin(out, buffer)))
			return (errmsg(), 1);
	}
	if (r < 0 || !out)
		return (free(out), errmsg(), 1);
	for (char *p = out; n && ((p = memmem(out, strlen(out), av[1], n))); p += n)
		memset(p, '*', n);
	printf("%s\n", out);
	free(out);
	return 0;
}