/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 14:00:03 by selow             #+#    #+#             */
/*   Updated: 2025/10/24 19:05:20 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// turk_sort utils
t_node	*find_cheapest(t_node *b)
{
	long	best_match_value;
	t_node	*best_match_node;
	t_node	*start;

	start = b;
	if (b == NULL)
		return (NULL);
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->push_cost < best_match_value)
		{
			best_match_value = b->push_cost;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = TRUE;
	return (get_cheapest(start));
}

t_node	*get_cheapest(t_node *stack)
{
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

t_node	*get_smallest(t_node *stack)
{
	t_node	*lowest;
	int		lowest_index;

	if (!stack)
		return (NULL);
	lowest = stack;
	lowest_index = stack->index;
	while (stack)
	{
		if (stack->index < lowest_index)
		{
			lowest = stack;
			lowest_index = stack->index;
		}
		stack = stack->next;
	}
	return (lowest);
}

void	refresh_median(t_node **stack)
{
	t_node	*cur;
	int		size;
	int		pos;
	int		median;

	cur = *stack;
	size = 0;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	median = size / 2;
	cur = *stack;
	pos = 0;
	while (cur)
	{
		cur->pos = pos;
		cur->above_median = (pos <= median);
		cur = cur->next;
		pos++;
	}
}

void	set_target_b(t_node *a, t_node *b)
{
	t_node	*cur_a;
	t_node	*target_node;
	long	best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		cur_a = a;
		while (cur_a)
		{
			if (cur_a->content > b->content
				&& cur_a->content < best_match_index)
			{
				best_match_index = cur_a->content;
				target_node = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (best_match_index == LONG_MAX)
			b->target_node = get_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}
