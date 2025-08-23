#include "pipex.h"

int	check_file(char *filename)
{
	if (access(filename, R_OK) != 0)
		error ;
	else if (access(filename, W_OK) != 0)
		error ;
	return (0);
}
