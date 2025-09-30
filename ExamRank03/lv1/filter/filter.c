#include "header.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

void	errmsg(void);

int	find_nl(char *str)
{
	int	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (1);
	return (0);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*temp;
	int		size;

	i = 0;
	size = strlen(str);
	temp = (char *)malloc(sizeof(char) * size + 1);
	while (i < size)
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*gnl(int fd)
{
	static char	buffer[10000];
	int		rs;
	int		i = 0;

	rs = read(fd, buffer, BUFFER_SIZE);
	if (rs < 0)
		errmsg();
	while ((rs = read(fd, buffer + i, BUFFER_SIZE)) > 0)
	{
		if (find_nl(buffer))
			break ;
		i += rs;
	}
	if (rs < 0)
	{
		errmsg();
		return (NULL);
	}
	buffer[i] = '\0';
	return (ft_strdup(buffer));
}

void	errmsg(void)
{
	perror("Error");
	return ;
}


int	main(int ac, char **av)
{
	char			*s1;
	char			*s2;
	char			*ptr;
	unsigned long	i;
	int				fd;

	if (ac != 2)
	{
		errmsg();
		return (1);
	}
	fd = 0;
	s1 = gnl(fd);
	s2 = av[1];
	ptr = s1;
	while ((ptr = memmem(ptr, strlen(ptr), s2, strlen(s2))))
	{
		i = 0;
		while (i < strlen(s2))
		{
			ptr[i] = '*';
			i++;
		}
		ptr = ptr + strlen(s2);
	}
	printf("Result is: %s\n", s1);
	free (s1);
	return (0);
}
