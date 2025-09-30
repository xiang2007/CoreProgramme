#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

static int	ft_strlen(char *str)
{
	int	i = 0;
	char c = '\n';

	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int	i;
	int	size1;
	int	size2;

	if (!s2)
		return (NULL);
	size2 = ft_strlen(s2);
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * size2);
		while (i < size2)
		{
			s1[i] = s2[i];
			i++;
		}
		return (s1);
	}
	else
	{
		size1 = ft_strlen(s1);
	}

}

char *get_next_line(int fd)
{
	static char *buffer;
	static char *after_nl;
	char		buffer;
	int			rs;
	int			size;

	rs = read(fd, &buffer, BUFFER_SIZE);
	if (rs > 0)
	{
		size = 
	}

}


