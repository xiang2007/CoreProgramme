#include "pipex.h"

int	main(int ac, char **av, char **ev)
{
	char *path;

	(void)av;
	if (ac > 1)
	{
		int i = 0;
		while (ev[i])
		{
			if (ft_strncmp("PATH", ev[i], 4) == 0)
				path = ev[i];
			i++;
		}
		path = getpath(av[1], &path);
		execve(path, av, ev);
		return (0);
	}
	return (0);
}