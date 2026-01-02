#ifndef BUF_SIZE
# define BUF_SIZE 10000
#endif

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	int		size;
	int		i = 0;
	char	*res;

	if (!str)
		return(NULL);
	size = ft_strlen(str);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	while(str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		sz1;
	int		sz2;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	if (s1 && s2)
	{
		sz1 = ft_strlen(s1);
		sz2 = ft_strlen(s2);
		res = malloc(sizeof(char) * (sz1 + sz2 + 1));
		if (!res)
			return (NULL);
	}
	i = 0;
	while (i < sz1)
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < sz2)
	{
		res[i + sz1] = s2[i];
		i++;
	}
	res[sz1 + sz2] = '\0';
	free(s1);
	return (res);
}

char	*readfile(int fd)
{
	char	*res = NULL;
	char	*temp;
	int		rs = 1;
	char	buffer[BUF_SIZE + 1];

	while (rs > 0)
	{
		rs = read(fd, buffer, BUF_SIZE);
		buffer[rs] = '\0';
		temp = ft_strjoin(res, buffer);
		res = temp;
	}
	return (res);

}

char	*get_one_line(int fd)
{
	static	char* str;
	static	int	i;
	static	int	j;
	int		k = 0;
	int		size;
	char	*res;

	if (!str)
	{
		str = readfile(fd);
		if (!str)
			return (NULL);
		i = 0;
		j = 0;
	}
	if (!str[j])
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	while (str[i] && str[i] != '\n')
		i++;
	size = i - j;
	if (str[i] == '\n')
		size++;
	res = malloc(sizeof(char) * (size + 1));
	while (k < size)
	{
		res[k] = str[k + j];
		k++;
	}
	res[k] = '\0';
	if (str[i] == '\n')
		i++;
	j = i;
	return (res);
}

char	*get_next_line(int fd)
{
	char	*oneline;

	oneline = get_one_line(fd);
	return (oneline);
}

int	main()
{
	int		fd;
	char	*res;

	fd = open("test.txt", O_RDONLY);
	res = get_next_line(fd);
	while (res)
	{
		printf("%s", res);
		free(res);
		res = get_next_line(fd);
	}
}
