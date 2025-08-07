#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack *stack_a;

	stack_a = asign_stack(ac, av);
	sort_three(stack_a);
	return (0);
}
