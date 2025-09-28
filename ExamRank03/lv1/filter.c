#define _GNU_SOURCE
#include <string.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	printerr(char **av)
{
	perror("Error");
	printf("\n");
	exit (1);
}

char	**open_and_read(void)
{
	int	fd;

	fd = open(

int main(int ac, char **av)
{
	if (ac != 2)
		printerr(NULL);
	else
		
}

