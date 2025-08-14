#include "push_swap.h"

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	if (is_stacksort((*stack_a)))
		return ;
	find_and_push(find_min_pos((*stack_a)), stack_a, stack_b);
	find_and_push(find_min_pos((*stack_a)), stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	print_stack(stack_a);
}
