#include "push_swap.h"

t_stack	*node_atoi(int len, char **str)
{
	int	i;
	long int	temp;
	t_stack		*stack;

	i = 1;
	stack = NULL;
	if (!str || len <= 1)
		return (NULL);
	while (i < len)
	{
		if (*str[i] == 32)
			i++;
		temp = ft_atoi(str[i]);
		if (stack == NULL)
			stack = ft_nodenew(temp, i);
		else
			ft_lstadd_back(&stack, ft_nodenew(temp, i));
		i++;
	}
	return (stack);
}

#include <stdio.h>

int main(int ac, char **av)
{
	t_stack *head;
	t_stack *current;
	int i = 0;

	head = node_atoi(ac, av);
	if (!head)
	{
		printf("Failed to create stack\n");
		return (1);
	}
	
	current = head;
	while (current)
	{
		printf("Value of %d is: %d\n", i, current->value);
		current = current->next;
		i++;
	}
	
	ft_lstclear(&head);  // Clear from the head
	return (0);
}
