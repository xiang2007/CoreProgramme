#include "pipex.h"
#include <stdio.h>

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)env;
	check_file(av[1]);
	return (0);
}