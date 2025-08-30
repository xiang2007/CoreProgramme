#include "pipex.h"

void	free_all(char **dptr)
{
	int	i;

	i = 0;
	while (dptr[i])
	{
		free (dptr[i]);
		i++;
	}
	free (dptr);
	return ;
}

int	check_path(char *path)
{
	if (ft_strnstr(path, "/usr/bin/", 9) != 0)
		return (1);
	return (0);
}