#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (!stack || stack->next == NULL)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	temp = stack->pos;
	stack->pos = stack->next->pos;
	stack->next->pos = temp;
}

void	sa(t_stack *stack_a)
{
	swap(stack_a);
	write(1, "sa", 2);
}

void	sb(t_stack *stack_b)
{
	swap(stack_b);
	write(1, "sb", 2);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write(1, "ss", 2);
}