#include "push_swap.h"

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stacksize((*stack_a));
	while (size > 1)
	{
		find_and_push(find_min_pos((*stack_a)), stack_a, stack_b);
		size--;
	}
	while (is_stack_reversed((*stack_b)))
		pb(stack_b, stack_a);
}
