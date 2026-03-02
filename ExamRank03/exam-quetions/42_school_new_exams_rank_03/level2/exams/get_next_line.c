#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

static int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

/*static char *ft_strjoin(char *s1, char *s2) //join s1 with s2, s1 head, s2 tail
{
	int		size1;
	int		size2;
	int		i = 0;
	int		j = 0;
	char	*temp;

	size1 = (s1) ? ft_strlen(s1) : 0;
	size2 = (s2) ? ft_strlen(s2) : 0;
	temp = (char *)malloc(sizeof(char) * (size1 + size2 + 1));
	if (s1)
	{
		while (s1[i])
		{
			temp[i] = s1[i];
			i++;
		}
	}
	if (s2)
	{
		while(s2[j])
		{
			temp[i + j] = s2[j];
			j++;
		}
	}
	temp[i +j] = '\0';
	free (s1);
	return (temp);
}*/

char	*ft_strdup(char *str)
{
	int		size = 0;
	int		i = 0;
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

int	findnl(char *str)
{
	int	i = 0;

	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static int	start = 0;
	static int	end = 0;
	int			rs;
	char		res[100000];
	char		buffer[100000];

	while ((rs = read(fd, buffer, BUFFER_SIZE)))
	{
		if (rs == 0)
			break ;
		if (findnl(buffer) == -1)
		{
			end += ft_strlen(buffer);
			while (start < end)
			{
				res[start] = buffer[start];
				start++;
			}
			res[start] = '\0';
			return (ft_strdup(res));
		}
		else
		{
			end += rs;
			while (start < rs)
			{
				res[start] = buffer[start];
				start++;
			}
			start += rs;
			res[start] = '\0';
		}
	}
	return (ft_strdup(res));
}

int	main()
{
	int		fd;
	char	*temp;

	fd = open("test.txt", O_RDONLY);
	while (1)
	{
		
		temp = get_next_line(fd);
		if (!temp)
			break ;
		printf("%s", temp);
		free (temp);
	}
	return (0);
}
