#include "minitalk.h"

void	sighandle(int signum)
{
	printf("signal is: %d\n", signum);
	exit(1);
}

int	main(void)
{
	signal(SIGINT, sighandle);
	while (1)
	{
		printf("sleep 1\n");
		sleep (1);
	}
	return (0);
}	
