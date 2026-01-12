/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_markup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:23:42 by selow             #+#    #+#             */
/*   Updated: 2025/10/24 17:04:45 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	max_markup(t_node *a, int clean)
{
	int	count;

	count = find_keep_set_max(a);
	if (!clean)
		clean_stack(&a);
	return (count);
}

int	add_keepflag_max(t_node *head, t_node *start)
{
	t_node	*stack;
	int		cur_i;

	stack = head;
	while (stack)
	{
		stack->keep = FALSE;
		stack = stack->next;
	}
	cur_i = start->index;
	start->keep = TRUE;
	stack = start->next;
	while (stack)
	{
		if (stack->index > cur_i)
		{
			stack->keep = TRUE;
			cur_i = stack->index;
		}
		stack = stack->next;
	}
	add_keepflag_max2(head, start, cur_i);
	return (count_keep(head));
}

void	add_keepflag_max2(t_node *head, t_node *end, int cur_i)
{
	t_node	*stack;

	stack = head;
	while (stack && stack != end)
	{
		if (stack->index > cur_i)
		{
			stack->keep = TRUE;
			cur_i = stack->index;
		}
		stack = stack->next;
	}
}

int	find_keep_set_max(t_node *a)
{
	t_node	*start;
	t_node	*best_start;
	int		count;
	int		max_count;

	if (!a)
		return (0);
	start = a;
	best_start = a;
	max_count = 0;
	while (start)
	{
		count = add_keepflag_max(a, start);
		if (count > max_count)
		{
			max_count = count;
			best_start = start;
		}
		start = start->next;
	}
	add_keepflag_max(a, best_start);
	return (max_count);
}
