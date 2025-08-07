#include "push_swap.h"

int	is_stacksort(t_stack *stack)
{
	int	flag;

	flag = 1;
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			flag *= 0;
		else
			stack = stack->next;
	}
	if (!flag)
		return (PASS);
	return (FAIL);
}

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
			return (PASS);
		break;
	}
	return (FAIL);
}

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
				return (FAIL);
			j++;
		}
		i++;
	}
	return (PASS);
}

int	is_sorted(char **str)
{
	int	i;
	int flag;
	int	nbr1;
	int	nbr2;

	if (!str)
		return (0);
	i = 1;
	flag = 1;
	while (str[i + 1])
	{
		nbr1 = ft_atoi(str[i]);
		nbr2 = ft_atoi(str[i + 1]);
		if (nbr1 > nbr2)
			flag *= 0;
		i++;
	}
	if (!flag)
		return (PASS);
	return (FAIL);
}

int	isvalid(char **str)
{
	int	i;

	i = 1;
	if (!str)
		return (FAIL);
	while (str[i])	
	{
		if (!onlynumbers(str[i]))
			return (FAIL);
		i++;
	}
	if ((!checkdup(str)) || (!is_sorted(str)))
		return (FAIL);
	return (PASS);
}
