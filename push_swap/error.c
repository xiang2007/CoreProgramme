#include "push_swap.h"

void	errmsg(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !*stack_a)
		ft_lstclear(stack_a);
	if (!stack_b || !*stack_b)
		ft_lstclear(stack_b);
	ft_putstr("ERROR\n");
	exit (1);
}