#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

int	ft_strlen(char *str)
{
	int	i = 0;

	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int	i;
	char	*res;

	if (!str)
		return (NULL);
	i = ft_strlen(str);
	res = (char *)malloc(sizeof(char) * i + 1);
	if (!res)
		return (NULL);
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int i, j, size1, size2 = 0;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
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
	free (s1);
	return (res);
}

int	findnl(char *str)
{
	int	i = 0;

	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (1);
}

char	*read_file(int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int	rs = 1;

	if 
	while (rs > 0)
	{
		rs = read(fd, buffer, BUFFER_SIZE + 1);
	}
}

char	*get_next_line(int fd)
{
	static char *remain;
	char	buffer[BUFFER_SIZE + 1];
	int		rs;

	if (fd < 0)
		return (NULL);
	rs = 1;
	while (rs > 0)
	{
		rs = read(fd, buffer, BUFFER_SIZE);
		if (rs == 0)
			break ;
		remain = ft_strjoin(remain, buffer);
	}


}

int	main()
{
	int		fd;
	char	*temp;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (0);
	temp = get_next_line(fd);
}