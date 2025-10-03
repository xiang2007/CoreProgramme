#include "philos.h"

void	printtime(void);

int	main()
{
	printtime();
	return (0);
}

void	printtime(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	while (((tv.tv_usec) / 1000) )
	{
		gettimeofday(&tv, NULL);
		printf("ms [%ld]\n", tv.tv_usec / 1000);
	}
	return ;
}