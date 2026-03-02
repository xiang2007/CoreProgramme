#include "get_next_line.h"

char	*strjoin(char *s, char c)
{
	int i = 0;
	char	*res;

	while (s && s[i])
		i++;
	res = malloc(i + 2);
	if (!res)
		return (NULL);
	i = 0;
	while (s && s[i])
	{
		res[i] = s[i];
		i++;
	}
	res[i++] = c;
	res[i] = '\0';
	free(s);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int pos, len;
	char	*line = NULL;

	while (1)
	{
		if (pos >= len)
		{
			len = read(fd, buffer, BUFFER_SIZE);
			pos = 0;
			if (len <= pos)
				return (line);
		}
		if (!(line = strjoin(line, buffer[pos])))
			return (NULL);
		if (buffer[pos++] == '\n')
			return (line);
	}
}