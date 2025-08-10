#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	if (!(*stack))
		return ;
	while (is_stacksort((*stack)))
	{
		if (((*stack)->value > (*stack)->next->value) && 
			((*stack)->value > ft_lstlast(*stack)->value))
				ra(stack);
		if ((*stack)->value > (*stack)->next->value)
			sa(stack);
		if ((*stack)->value > ft_lstlast(*stack)->value)
			rra(stack);
	}	
	return ;
}

/*void	sort(t_stack **stack_a, t_stack **stack_b)
{
	if (is_stack_reversed((*stack_a)) || is_stack_reversed(*stack_b))
		ss(stack_a, stack_b);
	print_stack(stack_a);
	printf("\n");
	print_stack(stack_b);
}*/

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

