#include "push_swap.h"

int	onlynumbers(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{	
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i + 1] >= '0' && str[i + 1] <= '9')
				i++;
		}
		if (str[i] >= '0' && str[i] <= '9')
			return (1);
		break;
	}
	return (0);
}
#include <stdio.h>
int	checkdup(char **str)
{
	int	i;
	int	j;
	long	nbr1;
	long	nbr2;

	i = 1;
	if (!str)
		return (0);
	while (str[i])
	{
		j = 1;
		nbr1 = ft_atoi(str[i]);
		while (str[j + i])
		{
			nbr2 = ft_atoi(str[j + i]);
			if (nbr1 == nbr2)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
int	isvalid(char **str)
{
	int	i;

	i = 1;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!onlynumbers(str[i]))
			return (0);
		i++;
	}
	if (!checkdup(str))
		return (0);
	return (1);
}
