#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int	main()
{
	char	*buffer;
	int		fd;

	fd = open("file.txt", O_RDONLY);
	buffer = get_next_line(fd);
	printf("%s\n",buffer);
	free(buffer);
	close(fd);
	return (0);
}
