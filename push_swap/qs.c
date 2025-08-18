/*#include "push_swap.h"

void	sort_stack_b(t_stack **stack_a, t_stack **stack_b);

void	partition_a(int pivot, t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stacksize(*stack_a);
	while (size--)
	{
		if ((*stack_a)->value < pivot)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
}

void	partition_b(int pivot, t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stacksize(*stack_b);
	while (size--)
	{
		if ((*stack_b)->value > pivot)
			pa(stack_a, stack_b);
		else
			rb(stack_b);
	}
}

int	choose_pivot(t_stack **stack)
{
	int	size;
	int	pivot;
	int	*temp;
	int	i;
	t_stack	*tmp_stack;

	size = stacksize((*stack));
	temp = (int *)malloc(sizeof(int) * size);
	tmp_stack = (*stack);
	i = 0;
	while (i < size)
	{
		temp[i] = tmp_stack->value;
		tmp_stack = tmp_stack->next;
		i++;
	}
	sort(temp, 0, size - 1);
	pivot = temp[(size - 1) / 2];
	free(temp);
	return (pivot);
}

void	sort_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pivot;

	size = stacksize((*stack_a));
	if (size <= 3)
	{
		sort_three(stack_a);
		return ;
	}
	pivot = choose_pivot(stack_a);
	partition_a(pivot, stack_a, stack_b);
	sort_stack_a(stack_a, stack_b);
	sort_stack_b(stack_a, stack_b);
}

void	sort_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	int	size;
	int	pivot;

	size = stacksize((*stack_b));
	if (size == 0)
		return ;
	if (size <= 3)
	{
		while (size--)
			pa(stack_a, stack_b);
		sort_three(stack_a);
		return ;
	}
	pivot = choose_pivot(stack_b);
	partition_b(pivot, stack_a, stack_b);
	sort_stack_a(stack_a, stack_b);
	sort_stack_b(stack_a, stack_b);
}


int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = asign_stack(ac, av);
	stack_b = NULL;
	sort_stack_a(&stack_a, &stack_b);
}*/