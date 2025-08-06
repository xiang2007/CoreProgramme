#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	long	result;

	sign = 1;
	result = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

int	stacksize(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

#include <stdio.h>
int	main(int ac, char **av)
{
	t_stack *stack;
	int	i;

	stack = asign_stack(ac, av);
	i = stacksize(stack);
	printf("Stack size is: %d\n", i);
	return (0);
}