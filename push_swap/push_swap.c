#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_b = (t_stack *)malloc(sizeof(t_stack));
	stack_b = NULL;
	if (ac > 2)
	{
		stack_a = asign_stack(ac, av);
		//save_three(&stack_a, &stack_b);
		//sort_three(&stack_a);
		//sort(&stack_a, &stack_b);
		//sort_five(&stack_a, &stack_b);
		print_pos(stack_a);
		sort_three(&stack_a);
		print_pos(stack_a);
		update_pos(stack_a);
		print_pos(stack_a);
		print_stack(&stack_b);
	}
}