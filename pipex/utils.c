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
}
