#ifndef BUF_SIZE
# define BUF_SIZE 10
#endif 

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

char	*strjoin(char *st1, char *st2)
{
	int	s1, s2;
	char	*res;

	s1 = (s1) ? strlen(st1) : 0;
	s2 = (s2) ? strlen(st2) : 0;
	res = malloc(s1 + s2 + 1);
	if (st1) { res = memmove(res, st1, s1); }
	if (st2) { res = memmove(res, st2, s2); }
	res[s1 + s2 + 1] = '\0';
	free(st1);
	return (res);
}

int	main(int ac, char **av)
{
	char	buffer[100000];
	char	*out;
	size_t	n = 0;
	int		r;

	if (ac == 2)
	{
		n = strlen(av[1]);
		while((r = read(0, buffer, BUF_SIZE)) > 0)
		{
			buffer[r] = '\0';
			if (!(out = strjoin(out, buffer)))
				return (perror("Error\n"), 1);
		}
		if (r < 0 || !out)
			return (perror("Error\n"), free(out), 1);
		for (char *p = out; n && p = memmem())
	}
}