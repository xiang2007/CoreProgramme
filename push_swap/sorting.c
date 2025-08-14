#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	if (!stack || !*stack || !(*stack)->next)
		return;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;

	if (a > b && a > c)
		ra(stack);
	if (b > a && b > c)
		rra(stack);
	a = (*stack)->value;
	b = (*stack)->next->value;
	if (a > b)
		sa(stack);
}

/*void	sort(t_stack **stack_a, t_stack **stack_b)
{
	if (is_stack_reversed((*stack_a)) || is_stack_reversed(*stack_b))
		ss(stack_a, stack_b);
	print_stack(stack_a);
	printf("\n");
	print_stack(stack_b);
}*/

