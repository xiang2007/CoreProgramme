#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack *head;
	t_stack *tail;

	if (!stack || !(*stack)->next || !*stack)
		return ;
	head = *stack;
	*stack = (*stack)->next;
	tail = ft_lstlast(*stack);
	tail->next = head;
	head->next = NULL;
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	write(1, "ra", 2);
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	write(1, "rb", 2);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr", 2);
}
