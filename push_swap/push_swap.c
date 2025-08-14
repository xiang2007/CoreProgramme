#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_b = (t_stack *)malloc(sizeof(t_stack));
	stack_b = NULL;
	if (ac > 2)
	{
		(void)stack_b;
		stack_a = asign_stack(ac, av);
		ft_sort(&stack_a, &stack_b);
	}
}