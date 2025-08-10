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
