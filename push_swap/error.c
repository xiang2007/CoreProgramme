#include "push_swap.h"

void	errmsg(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (!stack_a || !*stack_a)
		ft_lstclear(stack_a);
	if (!stack_b || !*stack_b)
		ft_lstclear(stack_b);
	ft_putstr("ERROR from ");
	ft_putstr(str);
	ft_putstr("\n");
	exit (1);
}