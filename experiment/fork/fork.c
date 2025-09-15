#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	pid_t	id;
	int		iid;

	(void)ac;
	(void)av;
	id = fork();
	if (id == 0)
		printf("%s\n", "im a child");
	else
		printf("%s\n", "im parent");
	exit (EXIT_SUCCESS);
}