#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack *stack_a;

	if (ac > 2)
	{
		stack_a = asign_stack(ac, av);
		sort_three(&stack_a);
	}
}