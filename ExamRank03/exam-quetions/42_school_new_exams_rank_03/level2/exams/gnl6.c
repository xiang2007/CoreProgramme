#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char	*strjoin(char *str, char c)
{
	int i;
	char *res;

	i = 0;
	while(str && str[i])
		i++;
	res = malloc(i + 2);
	if (!res)
		return (NULL);
	i = 0;
	while (str && str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i++] = c;
	res[i] = '\0';
	free(str);
	return (res);
}

char	*get_next_line(int fd)
{
	static int pos, len;
	static char buffer[BUFFER_SIZE];
	char	*line = NULL;

	while (1)
	{
		if (pos >= len)
		{
			len = read(fd, buffer, BUFFER_SIZE);
			if (len <= pos)
				return (line);
		}
		if (!(line = strjoin(line, buffer[pos])))
			return (NULL);
		if (buffer[pos++] == '\n')
			return (line);
	}
}