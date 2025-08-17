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

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return ;
}

int	stacksize(t_stack *stack)
{
	int	i;
	t_stack *temp;

	i = 0;
	temp = stack;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	asign_pos(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return ;
	while(stack)
	{
		stack->pos = i;
		stack = stack->next;
		i++;
	}
	return ;
}

int	find_highest_value(t_stack *stack)
{
	int	max;
	
	if (!stack)
		return (0);
	max = stack->value;
	while (stack->next)
	{
		if ((stack->value) > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}