#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack *head;
	t_stack *tail;

	if (!stack || !*stack || !(*stack)->next)
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
	ft_putstr("ra\n");
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
