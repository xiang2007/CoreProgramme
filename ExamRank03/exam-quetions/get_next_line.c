#include "get_next_line.h"

char	*ft_strjoin(char *s1, char c)
{
	int	i;
	char	*res;

	i = 0;
	while (s1 && s1[i])
		i++;
	res = malloc(i + 2);
	if (!res)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i++] = c;
	res[i] = '\0';
	free(s1);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	static int len, pos;
	char	*line;

	while (1)
	{
		if (pos >= len)
		{
			len = read(fd, buffer, BUFFER_SIZE);
			pos = 0;
			if (len <= 0)
				return (line);
		}
		if (!(line = ft_strjoin(line, buffer[pos])))
			return (NULL);
		if (buffer[pos++] ==  '\n')
			return (line);
	}
}