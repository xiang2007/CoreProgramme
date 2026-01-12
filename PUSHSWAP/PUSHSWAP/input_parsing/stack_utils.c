/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:17:16 by selow             #+#    #+#             */
/*   Updated: 2025/07/14 12:45:06 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_sorted(t_node	*stack)
{
	t_node	*currentnode;

	currentnode = stack;
	while (currentnode->next)
	{
		if (currentnode->content > currentnode->next->content)
			return (0);
		currentnode = currentnode->next;
	}
	return (1);
}

int	stack_sizeof(t_node **a)
{
	int		count;
	t_node	*current_node;

	current_node = *a;
	count = 0;
	while (current_node)
	{
		current_node = current_node->next;
		count += 1;
	}
	return (count);
}

t_node	*copy_stack(t_node *stack)
{
	t_node	*newnode;
	t_node	*new_stack;

	new_stack = NULL;
	while (stack)
	{
		newnode = stack_newnode_copy(stack);
		if (!newnode)
		{
			clean_stack(&new_stack);
			return (NULL);
		}
		stack_addback(&new_stack, newnode);
		stack = stack->next;
	}
	return (new_stack);
}

t_node	*stack_newnode_copy(t_node *src)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	*new = *src;
	new->content = src->content;
	new->index = src->index;
	new->pos = src->pos;
	new->target_node = src->target_node;
	new->above_median = src->above_median;
	new->push_cost = src->push_cost;
	new->cheapest = src->cheapest;
	new->next = NULL;
	new->prev = NULL;
	new->keep = -1;
	return (new);
}

void	clean_stack(t_node **head)
{
	t_node	*tmp;

	if (!head)
		return ;
	while ((*head)->prev)
		*head = (*head)->prev;
	while (*head)
	{
		tmp = (*head)->next;
		free(*head);
		*head = tmp;
	}
}
