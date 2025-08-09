#include "push_swap.h"

void	print_stack(t_stack **stack)
{
	while (stack)
	{
		printf("Value of stack is: %d\n", (*stack)->value);
		(*stack) = (*stack)->next;
	}
}
