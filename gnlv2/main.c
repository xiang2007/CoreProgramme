#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int	main()
{
	int fd;
	int	i = 10;

	fd = open("file.txt", O_RDONLY);
	while (i--)
		printf("%s",get_next_line(fd));
	return (0);
}