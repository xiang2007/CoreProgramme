/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:18:18 by selow             #+#    #+#             */
/*   Updated: 2025/10/24 17:03:45 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	ft_swap_node(t_node *a, t_node *b)
{
	int	tmp;

	tmp = a->content;
	a->content = b->content;
	b->content = tmp;
}

static t_node	*partition(t_node *low, t_node *high)
{
	int		pivot;
	t_node	*i;
	t_node	*j;

	pivot = high->content;
	i = low->prev;
	j = low;
	while (j != high)
	{
		if (j->content <= pivot)
		{
			if (i == NULL)
				i = low;
			else
				i = i->next;
			ft_swap_node(i, j);
		}
		j = j->next;
	}
	if (i == NULL)
		i = low;
	else
		i = i->next;
	ft_swap_node(i, high);
	return (i);
}

static void	_quicksort(t_node *low, t_node *high)
{
	t_node	*p;

	if (low && high && low != high && low != high->next)
	{
		p = partition(low, high);
		_quicksort(low, p->prev);
		_quicksort(p->next, high);
	}
}

t_node	*quicksort_stack(t_node *stack)
{
	t_node	*head;
	t_node	*tail;

	head = stack;
	tail = stack;
	while (tail && tail->next)
		tail = tail->next;
	_quicksort(head, tail);
	return (stack);
}
