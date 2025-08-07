#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	int	size;
	int	max;

	if (!(*stack) || !stack || is_stacksort((*stack)))
		return ;
	size = stacksize(*stack);
	max = find_highest_value((*stack));
	while (!is_stacksort((*stack)))
	{
		if ((*stack)->value == max)
			rra(stack);
		if ((*stack)->next->value == max)
			rra(stack);
		if ((*stack)->next->next->value == max)
			sa(stack);
	}
	return ;
}

