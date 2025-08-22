#include "pipex.h"

int	check_file(char *filename)
{
	if (access(filename, R_OK) != 0)
	{
		perror(filename);
		exit(1)
	}
	else if (access(filename, W_OK) != 0)
		perror(filename);
	return (1);
}

int check_command(char *command)
{

}