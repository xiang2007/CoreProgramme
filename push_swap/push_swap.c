#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!stack_b)
		return (errmsg);
	stack_b = NULL;
	if (ac > 2)
	{
		if (ac <= 51)
		{
			stack_a = asign_stack(ac, av);
			ft_selection(&stack_a, &stack_b);
		}
	}
}