/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 13:25:51 by selow             #+#    #+#             */
/*   Updated: 2025/10/24 17:02:01 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	sa(t_node **a, int to_print)
{
	t_node	*first;
	t_node	*second;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*a = second;
	if (to_print)
		ft_printf_fd(1, "sa\n");
}

void	pb(t_node **a, t_node **b, int to_print)
{
	t_node	*a_first;
	t_node	*a_second;

	if (!a || !*a)
		return ;
	a_first = *a;
	a_second = a_first->next;
	if (a_second)
		a_second->prev = NULL;
	a_first->next = *b;
	if (*b)
		(*b)->prev = a_first;
	a_first->prev = NULL;
	*a = a_second;
	*b = a_first;
	if (to_print)
		ft_printf_fd(1, "pb\n");
}

void	ra(t_node **a, int to_print)
{
	t_node	*first;
	t_node	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	*a = first->next;
	(*a)->prev = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	if (to_print)
		ft_printf_fd(1, "ra\n");
}

void	pa(t_node **a, t_node **b, int to_print)
{
	t_node	*tmp;

	if (!b || !*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	tmp->next = *a;
	if (*a)
		(*a)->prev = tmp;
	tmp->prev = NULL;
	*a = tmp;
	if (to_print)
		ft_printf_fd(1, "pa\n");
}

void	rr(t_node **a, t_node **b, int to_print)
{
	if (!a || !*a || !b || !*b)
		return ;
	if (a && *a && (*a)->next)
		ra(a, FALSE);
	if (b && *b && (*b)->next)
		rb(b, FALSE);
	if (to_print)
		ft_printf_fd(1, "rr\n");
}
