#include "pipex.h"
#include <stdio.h>

int main(int ac, char **av, char **env)
{
	(void)av;
	char *path;

	if (ac == 5)
	{
		if (check_file(av[1]), 1)
		{
			path = getpath("ls", &env[65]);
		}
	}
	
	ft_printf("%s\n", path);
	return (0);
}