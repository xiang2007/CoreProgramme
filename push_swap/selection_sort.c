#include "push_swap.h"

void	ft_selection(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stacksize((*stack_a));
	if (size <= 5)
	{
		find_and_push(find_min_pos(*stack_a), stack_a, stack_b);
		find_and_push(find_min_pos(*stack_a), stack_a, stack_b);
		sort_three(stack_a);
		while (*stack_b)
			pa(stack_a, stack_b);
		return ;
	}
	while (size - 3)
	{
		find_and_push(find_min_pos((*stack_a)), stack_a, stack_b);
		size--;
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
}
