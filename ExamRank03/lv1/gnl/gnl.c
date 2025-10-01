# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

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
	int	size;
	int	i = 0;
	char	*res;

	if (!str)
		return (NULL);
	size = ft_strlen(str);
	res = (char *)malloc(sizeof(char) * size + 1);
	if (!res)
	{
		errmsg();
		return (NULL);
	}
	while (i < size)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*get_file(int fd)
{
	static char	res[100000];
	char		buffer[BUFFER_SIZE + 1];
	int			rs;
	int			i;
	static int	j;

	if (fd < 0)
	{
		errmsg();
		return (NULL);
	}
	while ((rs = read(fd, buffer, BUFFER_SIZE)))
	{
		i = 0;
		buffer[rs] = '\0';
		while (buffer[i])
		{
			res[i + j] = buffer[i];
			i++;
		}
		j += ft_strlen(buffer);
	}
	res[j] = '\0';
	return res;
}

char	*get_next_line(int	fd)
{
	int			i;
	int			flag = 1;
	static int	j;
	int			rs;
	static char *str;
	char		buffer[BUFFER_SIZE + 1];
	char		res[100000];

	while ((rs = read(fd, buffer, BUFFER_SIZE)) && flag)
	{
		i = 0;
		buffer[rs] = '\0';
		while (buffer[i])
		{
			res[i + j] = buffer[i];
			i++;
		}
		j += ft_strlen(buffer);
	}
	flag = 0;
	i = 0;
	j = 0;
	while(str[j] && str[j] != '\n')
	{
		res[i] = str[j];
		i++;
		j++;	
	}
	if (str[j] == '\n')
		j++;
	res[i] = '\0';
	return (ft_strdup(res));
}

int	main(void)
{
	int		fd;
	char	*res;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while (1)
	{
		res = get_next_line(fd);
		printf("res is: %s\n", res);
		if (!res)
			break ;
		free (res);		
	}
	return (0);
}
