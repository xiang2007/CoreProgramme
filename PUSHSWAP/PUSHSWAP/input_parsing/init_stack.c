/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 12:06:21 by selow             #+#    #+#             */
/*   Updated: 2025/09/13 20:11:14 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*stack_newnode(int content)
{
	t_node	*newnode;

	newnode = malloc(sizeof(t_node));
	if (newnode == NULL)
		return (NULL);
	newnode->content = content;
	newnode->index = -1;
	newnode->keep = FALSE;
	newnode->pos = -1;
	newnode->target_node = NULL;
	newnode->above_median = -1;
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->push_cost = 0;
	newnode->cheapest = FALSE;
	return (newnode);
}

int	stack_addback(t_node **lst, t_node *newnode)
{
	t_node	*lastnode;

	if (!lst || !newnode)
		return (0);
	if (*lst == NULL)
	{
		*lst = newnode;
		return (1);
	}
	lastnode = *lst;
	while (lastnode->next)
	{
		if (lastnode == newnode)
			return (1);
		lastnode = lastnode->next;
	}
	lastnode->next = newnode;
	newnode->prev = lastnode;
	return (1);
}

void	stack_create_and_push(t_node **stack, int *int_arr, int len)
{
	t_node	*newnode;
	int		i;

	if (!stack || !int_arr || len <= 0)
		return ;
	i = -1;
	while (++i < len)
	{
		newnode = stack_newnode(int_arr[i]);
		if (!newnode)
		{
			clean_stack(stack);
			return ;
		}
		stack_addback(stack, newnode);
	}
}

/*
FOR TESTING IF THE CODE:
	INITIALISES A NODE AND APPEND IT AT THE BACK OF THE STACK (LINKED LIST)
	PRINTS OUT WHAT IS IN THE STACK
*/
/*
int main(void)
{
	t_node *stack;
	int	num;
	
	stack = NULL;
	num = 9;
	int num2 = 5;
	int num3 = 6;
	stack_create_and_push(&stack, num);
	stack_create_and_push(&stack, num2);
	stack_create_and_push(&stack, num3);

	t_node	*current = stack;

	// to see what is in the stack
	int count = 1;
	printf("===Inside the stack===\n");
	while (current)
	{
		printf("stack element #%d: %d\n", count, current->content);
		current = current->next;
		count += 1;
	}
	return (0);
}
*/
/*
typedef struct s_list {
	void	*content;
	t_list *next;
}	t_list;

t_list	*node = malloc(sizeof(t_list));
*/
