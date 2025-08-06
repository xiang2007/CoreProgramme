#include "push_swap.h"

void	bubblesort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *next;

	next = (*stack_a)->next;
	if (!stack_a || !stack_b)
		return ;
	while (!is_sorted(stack_a) || !is_sorted(stack_b))
	{
		if ((*stack_a)->value < next->value)
			pa(stack_a, stack_b);
	}
}