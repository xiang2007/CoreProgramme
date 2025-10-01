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
	temp = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
	if (!temp)
	{
		errmsg();
		free(s1);
		return (NULL);
	}
	if (s1)
		memcpy(temp, s1, size1);
	if (s2)
		memcpy(temp + size1, s2, size2);
	temp[size1 + size2] = '\0';
	free (s1);
	return (temp);

}

int	check_nl(char *str)
{
	int i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	char	buffer[1000000];
	char	*out = NULL;
	char	*tofind;
	char	*ptr;
	int		rs;
	int		fd;
	size_t		i = 0;

	fd = 0;
	if (ac != 2)
	{
		errmsg();
		return (1);
	}
	tofind = av[1];
	while ((rs = read(fd, buffer, BUF_SIZE)) > 0)
	{
		buffer[rs] = '\0';
		out = ft_strjoin(out, buffer);
	}
	ptr = out;
	if (rs < 0 || !out)
	{
		free (out);
		errmsg();
		return (1);
	}
	while ((out = memmem(out, strlen(out), tofind, strlen(tofind))))
	{
		i = 0;
		while (i < strlen(tofind))
		{
			out[i] = '*';
			i++;
		}
		out += strlen(tofind);
	}
	printf("%s", ptr);
	// free (out);
	free (ptr);
	return (0);
}