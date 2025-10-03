# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

static int	find_nl(char *str)
{
	int	i = 0;

	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i);
	return (0);
}
static int	ft_strlen(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	errmsg(void)
{
	perror("Error");
	return ;
}

char	*ft_strdup(char *str)
{
	int	i = 0;
	int	size;
	char	*temp;

	if (!str)
		return (NULL);
	size = ft_strlen(str);
	temp = (char *)malloc(sizeof(char) * size + 1);
	while (i < size)
	{
		temp[i] = str[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	i = 0;
	int	j = 0;
	int	size1;
	int	size2;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	size1 = (s1) ? ft_strlen(s1) : 0;
	size2 = (s2) ? ft_strlen(s2) : 0;
	res = (char *)malloc(sizeof(char) * size1 + size2 + 1);
	if (s1)
	{
		while (i < size1)
		{
			res[i] = s1[i];
			i++;
		}
	}
	if (s2)
	{
		while (j < size2)
		{
			res[i + j] = s2[j];
			j++;
		}
	}
	res[i + j] = '\0';
	if (s1)
		free (s1);
	return (res);
}

char	*extract(char *str)
{
	int	i = 0;
	int	size;
	char	*res;

	if (!str)
		return (NULL);
	size = ft_strlen(str);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	while (i < size)
	{
		if (str[i] == '\n')
			break ;
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*cleanup(char *str)
{
	int		i = 0;
	int		size;
	int		nl;
	char	*res;

	if (!str)
		return (NULL);
	size = ft_strlen(str);
	nl = find_nl(str);
	res = (char *)malloc(sizeof(char) * (size - nl));
	while (i < (size - nl))
	{
		res[i] = str[nl + i];
		i++;
	}
	if (res[i] == '\n')
		res[i] = '\0';
	res[i] = '\0';
	free (str);
	return (res);
}


char	*get_next_line(int fd)
{
	int			rs;
	static char *remain = NULL;
	char		buffer[100000];
	char		*res = NULL;

	if (fd < 0)
	{
		errmsg();
		return (NULL);
	}
	rs = read(fd, buffer, BUFFER_SIZE);
	while (rs > 0)
	{
		if (find_nl(buffer) > 0)
		{
			remain = ft_strjoin(remain, buffer);
			break ;
		}
		else
			remain = ft_strjoin(remain, buffer);
		rs = read(fd, buffer, BUFFER_SIZE);
	}
	if (rs == 0)
	{
		printf("res is: %s\n", res);
		res = NULL;
		return (res);
	}
	res = extract(remain);
	remain = cleanup(remain);
	//printf("res is: %s\n", res);
	return (res);
}

int	main(void)
{
	int		fd;
	char	*res;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while ((res = get_next_line(fd)))
	{
		printf("res is: %s\n", res);
		free (res);
	}
	return (0);
}
