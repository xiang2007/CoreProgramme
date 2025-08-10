#include "push_swap.h"

void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *temp;

	if (!stack_a || !*stack_a)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = *stack_b;
	*stack_b = *stack_a;
	*stack_a = temp;
}

void pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !*stack_a)
		return ;
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}

void pa(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_b || !*stack_b)
		return  ;
	push(stack_b, stack_a);
	ft_putstr("pa\n");
}

