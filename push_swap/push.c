#include "push_swap.h"

void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;

	if (!*stack_a)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = *stack_b;
	*stack_b = *stack_a;
	*stack_a = temp;
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	write(1, "pa", 2);
}

void pb(t_stack **stack_b, t_stack **stack_a)
{
	push(stack_b, stack_a);
	write(1, "pb", 2);
}

