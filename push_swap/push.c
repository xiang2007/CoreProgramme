#include "push_swap.h"

void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;

	if (!stack_a || !(*stack_a)->next || !*stack_a
			|| !stack_b || !(*stack_b)->next || !*stack_b)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = *stack_b;
	*stack_b = *stack_a;
	*stack_a = temp;
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pa\n");
}

void pb(t_stack **stack_b, t_stack **stack_a)
{
	push(stack_b, stack_a);
	ft_putstr("pb\n");
}

