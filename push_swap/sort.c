#include "push_swap.h"

void	ft_selection(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stacksize((*stack_a));
	while (size > 1)
	{
		find_and_push(find_min_pos((*stack_a)), stack_a, stack_b);
		size--;
	}
	while (*stack_b)
		pa(stack_a, stack_b);
}
