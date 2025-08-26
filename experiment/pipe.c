#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	int	pipe_fd[2];
	int	fd;

	(void)ac;
	if (pipe(pipe_fd) == -1)
		exit (EXIT_FAILURE);
	fd = open("test.txt", O_WRONLY | O_CREAT, 0777);
	if (fd == -1)
		exit (EXIT_FAILURE);
	dup2(pipe_fd[0], STDIN_FILENO);
	dup2(fd, pipe_fd[1]);
	write(pipe_fd[1], av[1], strlen(av[1]));
	//close(pipe_fd[0]);
	//close(pipe_fd[1]);
	exit (EXIT_SUCCESS);
}