#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("Value of stack is: %d\n", stack->value);
		stack = stack->next;
	}
}

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
	}	return ;
}

