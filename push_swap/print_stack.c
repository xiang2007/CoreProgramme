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

void	print_pos(t_stack *stack)
{
	int	i;
	t_stack *temp;

	i = 0;
	temp = stack;
	while (temp)
	{
		printf("Stack nbr %d has pos %d and value %d\n", i, temp->pos, temp->value);
		i++;
		temp = temp->next;
	}
}
