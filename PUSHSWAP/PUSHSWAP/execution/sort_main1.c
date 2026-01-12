/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 01:07:12 by selow             #+#    #+#             */
/*   Updated: 2025/10/24 19:03:56 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_both(t_node **a, t_node **b, t_node *cheapest);

void	turk_sort(t_node **a, t_node **b)
{
	t_node	*target;

	while (*b)
	{
		refresh_median(a);
		refresh_median(b);
		set_target_b(*a, *b);
		calculate_costs(*a, *b);
		target = find_cheapest(*b);
		prep_to_push(a, b, target);
		pa(a, b, TRUE);
	}
	refresh_median(a);
	min_at_top(*a);
}

void	prep_to_push(t_node **a, t_node **b, t_node *cheapest)
{
	rotate_both(a, b, cheapest);
	while (*b != cheapest)
	{
		if (cheapest->above_median)
			rb(b, TRUE);
		else
			rrb(b, TRUE);
	}
	while (*a != cheapest->target_node)
	{
		if (cheapest->target_node->above_median)
			ra(a, TRUE);
		else
			rra(a, TRUE);
	}
}

static void	rotate_both(t_node **a, t_node **b, t_node *cheapest)
{
	while (*b != cheapest && *a != cheapest->target_node)
	{
		if (cheapest->above_median
			&& cheapest->target_node->above_median)
			rr(a, b, TRUE);
		else if (!cheapest->above_median
			&& !cheapest->target_node->above_median)
			rrr(a, b, TRUE);
		else
			break ;
	}
}

void	calculate_costs(t_node *a, t_node *b)
{
	int		size_a;
	int		size_b;

	size_a = stack_sizeof(&a);
	size_b = stack_sizeof(&b);
	(void)a;
	while (b)
	{
		b->push_cost = b->pos;
		if (!(b->above_median))
			b->push_cost = size_b - (b->pos);
		if (b->target_node->above_median)
			b->push_cost += b->target_node->pos;
		else
			b->push_cost += size_a - (b->target_node->pos);
		b = b->next;
	}
}

void	min_at_top(t_node *a)
{
	while ((a)->content != get_smallest(a)->content)
	{
		if (get_smallest(a)->above_median)
			ra(&a, TRUE);
		else
			rra(&a, TRUE);
	}
}
