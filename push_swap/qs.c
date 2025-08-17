#include "push_swap.h"

void partition(int pivot, t_stack **stack_a, t_stack **stack_b)
{
	int size;
	int i;

	size = stacksize(*stack_a);
	i = 0;
	while (i < size)
	{
		if((*stack_a)->value < pivot)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
}

void sort_stack(int pivot, t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a || !*stack_b)
		errmsg(NULL, NULL);
	partition(pivot, stack_a, stack_b);
}

int main(int ac, char **av)
{
	int pivot;
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = asign_stack(ac, av);
	stack_b = malloc(sizeof(t_stack));
	pivot = quicksort(ac, av);
	partition(pivot, &stack_a, &stack_b);
}