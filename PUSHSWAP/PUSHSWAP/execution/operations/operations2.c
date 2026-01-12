/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 14:47:59 by selow             #+#    #+#             */
/*   Updated: 2025/10/24 16:57:12 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	rrr(t_node **a, t_node **b, int to_print)
{
	if (a && *a && (*a)->next)
		rra(a, FALSE);
	if (b && *b && (*b)->next)
		rrb(b, FALSE);
	if (to_print)
		ft_printf_fd(1, "rrr\n");
}

void	rra(t_node **a, int to_print)
{
	t_node	*last;
	t_node	*before_last;

	if (!a || !*a || !(*a)->next)
		return ;
	last = *a;
	while (last->next)
		last = last->next;
	before_last = last->prev;
	before_last->next = NULL;
	last->prev = NULL;
	last->next = *a;
	(*a)->prev = last;
	*a = last;
	if (to_print)
		ft_printf_fd(1, "rra\n");
}

void	rrb(t_node **b, int to_print)
{
	t_node	*last;
	t_node	*before_last;

	if (!b || !*b || !(*b)->next)
		return ;
	last = *b;
	while (last->next)
		last = last->next;
	before_last = last->prev;
	before_last->next = NULL;
	last->prev = NULL;
	last->next = *b;
	(*b)->prev = last;
	*b = last;
	if (to_print)
		ft_printf_fd(1, "rrb\n");
}

void	rb(t_node **b, int to_print)
{
	t_node	*first;
	t_node	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	last = *b;
	while (last->next)
		last = last->next;
	*b = first->next;
	(*b)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (to_print)
		ft_printf_fd(1, "rb\n");
}
