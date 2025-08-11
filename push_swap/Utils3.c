#include "push_swap.h"

int	is_stack_reversed(t_stack *stack)
{
	int	sign;
	t_stack *temp;

	sign = 1;
	if (!stack)
		return (0);
	temp = stack;
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			temp = temp->next;
		else
			sign = 0;
	}
	if (!sign)
		return (0);
	return (1);
}

int	find_min_value_pos(t_stack *stack)
{
	int	min;
	int	pos;
	
	if (!stack)
		return (0);
	update_pos(stack);
	min = stack->value;
	pos = stack->pos;
	while (stack->next)
	{
		if ((stack->value) < min)
		{
			min = stack->value;
			pos = stack->pos;
		}
		pos = stack->pos;
		stack = stack->next;
	}
	return (pos);
}

void	update_pos(t_stack *stack)
 {
	int	i;

	if (!stack)
		return ;
	i = 1;
	while (stack->next)
	{
		stack->pos = i;
		stack = stack->next;
		i++;
	}
	return ;
 }
