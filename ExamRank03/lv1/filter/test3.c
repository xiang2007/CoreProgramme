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