#include "push_swap.h"

void	triplesort(t_stack *stack)
{
	if (stack || stack->next || (is_sorted(stack)))
	{
		if (stack->value > stack->next->value > stack->next->next->value)
		{
			ra(stack);
			sa(stack);
		}
		if ()
	}
}