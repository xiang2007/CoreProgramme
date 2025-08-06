#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack *head;
	t_stack *tail;

	if (!stack || !(*stack)->next || !*stack)
		return ;
	head = (*stack)->next;
	tail = ft_lstlast(*stack);
	head->next = NULL;
	tail->next = head;
	*stack = head;
}

void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra", 3);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb", 3);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write(1, "rrr", 3);
}