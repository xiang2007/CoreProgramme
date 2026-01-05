#ifndef BUF_SIZE
# define BUF_SIZE 10
#endif

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

void	errmsg(void)
{
	perror ("Error");
	printf("\n");
	return ;
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*temp;
	int		size1;
	int		size2;

	size1 = (s1) ? strlen(s1) : 0;
	size2 = (s2) ? strlen(s2) : 0;
	temp = malloc(size1 + size2 + 1);
	if (s1)	memcpy(temp, s1, size1);
	if (s2) memcpy(temp + size1, s2, size2);
	temp[size1 + size2] = '\0';
	free (s1);
	return (temp);

}

int	main(int ac, char **av)
{
	char	buf[BUF_SIZE + 1];
	char	*out = NULL;
	size_t	n = 0;
	ssize_t	r;

	if (ac != 2)
		return (errmsg(), 1);

	n = strlen(av[1]);
	while ((r = read(0, buf, BUF_SIZE)) > 0)
	{
		buf[r] = 0;
		if (!(out = ft_strjoin(out, buf)))
			return (errmsg(), 1);
	}
	if (r < 0 || !out)
		return (free(out), errmsg(), 1);

	for (char *p = out; n && (p = memmem(p, strlen(p), av[1], n)); p += n)
		memset(p, '*', n);

	printf("%s", out);
	free(out);
	return (0);
}