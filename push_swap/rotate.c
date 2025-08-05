#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack *temp;
	t_stack *tail;

	temp = (*stack)->next;
	tail = ft_lstlast(*stack)->next;
	*stack = temp;
}