#include "get_next_line.h"

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
	int	i = 0;
	int	size = 0;
	char	*res;

	if (!str)
		return (NULL);
	size = ft_strlen(str);
	res = malloc(sizeof(char) * (size + 1));
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
	int	sz1;
	int	sz2;
	int	i = 0;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	sz1 = ft_strlen(s1);
	sz2 = ft_strlen(s2);
	res = malloc(sizeof(char) * (sz1 + sz2 + 1));
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
	int	rs = 1;
	char	*res = NULL;
	char	*temp;
	char	buffer[10000];

	while (rs > 0)
	{
		rs = read(fd, buffer, BUFFER_SIZE);
		if (rs > 0)
			buffer[rs] = '\0';
		temp = ft_strjoin(res, buffer);
		res = temp;
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*file;
	static int	i;
	static int	j;
	int			k = 0;
	int			size = 0;
	char		*res;

	if (!file)
	{
		file = readfile(fd);
		if (!file)
			return (NULL);
		i = 0;
		j = 0;
	}
	if (file[j] == '\0')
	{
		free(file);
		file = NULL;
		return (NULL);
	}
	i = j;
	while (file[i] && file[i] != '\n')
		i++;
	size = i - j;
	res = malloc(sizeof(char) * (size + 2));
	while (k < size)
	{
		res[k] = file[k + j];
		k++;
	}
	if (file[i] == '\n')
	{
		res[k++] = '\n';
		i++;
	}
	res[k] = '\0';
	j = i;
	return (res);
}