#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_b = NULL;
	if (ac > 2)
	{
		if (ac <= 4)
		{
			stack_a = asign_stack(ac, av);
			sort_three(&stack_a);
		}
		else if(ac <= 70)
		{
			stack_a = asign_stack(ac, av);
			ft_selection(&stack_a, &stack_b);
		}
		else
		{
			stack_a = asign_stack(ac, av);
			asign_array(&stack_a);
			radix_sort(&stack_a, &stack_b);
		}
		ft_lstclear(&stack_a);
		ft_lstclear(&stack_b);
	}
}
