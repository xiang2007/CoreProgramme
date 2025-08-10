#include "push_swap.h"

void	print_stack(t_stack **stack)
{
	t_stack *temp;

	temp = (*stack);
	while (temp)
	{
		printf("Value of stack is: %d\n", temp->value);
		temp = temp->next;
	}
}
