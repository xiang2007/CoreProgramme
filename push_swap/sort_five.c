#include "push_swap.h"

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int count;

	count = 2;
	save_three(stack_a, stack_b);
	sort_three(stack_a);
	while (!is_stacksort((*stack_a)) || count)
	{
		while (count)
		{
			pa(stack_a, stack_b);
			count--;
		}
			if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
		if ((*stack_a)->value > ft_lstlast((*stack_a))->value)
			ra(stack_a);
	}
	print_stack(stack_a);
	return ;
}
