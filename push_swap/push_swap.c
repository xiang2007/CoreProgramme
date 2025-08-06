#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack **stack_a;
	t_stack **stack_b;

	stack_a = asign_stack(ac, av);
	stack_b = NULL;
	bubblesort(stack_a, stack_b);
	return (0);
}
