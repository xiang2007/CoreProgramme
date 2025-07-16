#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main()
{
	int fd;
	char	*buffer;
	int		read_b;
	int	i = 0;

	fd = open("file.txt", O_RDONLY);
	printf("%d\n",fd);
	buffer = malloc(BUFFER_SIZE);
	read_b = read(fd, buffer, BUFFER_SIZE);
	printf("%d\n",read_b);
	while ((buffer[i] != '\n') && i < read_b)
		i++;
	printf("%d\n",i);
	return (0);
}