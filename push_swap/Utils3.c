#include "push_swap.h"

int	is_stack_reversed(t_stack *stack)
{
	int	sign;
	t_stack *temp;

	sign = 1;
	if (!stack)
		errmsg (&stack, NULL, "stack reversed");
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

int	find_min_pos(t_stack *stack)
{
	int	min;
	int	pos;
	
	if (!stack)
		errmsg (&stack, NULL, "find min pos");
	min = stack->value;
	pos = stack->pos;
	while (stack)
	{
		if ((stack->value) < min)
		{
			min = stack->value;
			pos = stack->pos;
		}
		stack = stack->next;
	}
	return (pos);
}

void	update_pos(t_stack *stack)
{
	int	i;
	t_stack *temp;

	if (!stack)
		errmsg(&stack, NULL, "update pos");
	temp = stack;
	i = 0;
	while (temp)
	{
		temp->pos = i;
		temp = temp->next;
		i++;
	}
	return ;
}

void	save_three(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stacksize((*stack_a));
	while (size - 3)
	{
		pb(stack_a, stack_b);
		size--;
	}
}

void	find_and_push(int pos, t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (!stack_a || !*stack_a)
		errmsg (stack_a, stack_b, "fap");
	size = stacksize(*stack_a);
	if (pos < 0 || pos >= size)
		errmsg (stack_a, stack_b, "pos in fap");
	if (pos <= size / 2)
	{
		while (pos != (*stack_a)->pos)
			ra(stack_a);
	}
	else
	{
		while (pos != (*stack_a)->pos)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	if (*stack_a)
		update_pos(*stack_a);
}
