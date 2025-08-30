#include "pipex.h"

void	error(int val)
{
	if (val > 1)
	{
		perror("Error");
		exit(127);
	}
	perror("Error");
		exit(EXIT_FAILURE);
}