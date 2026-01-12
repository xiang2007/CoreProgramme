/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markup_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/28 02:08:58 by selow             #+#    #+#             */
/*   Updated: 2025/10/24 19:02:05 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	add_keepflag(t_node *a, int markup)
{
	int	count;

	count = 0;
	if (markup == MAX)
		count = find_keep_set_max(a);
	return (count);
}

int	sa_better(t_node *a, int markup)
{
	int	before;
	int	after;

	add_keepflag(a, markup);
	before = count_keep(a);
	sa(&a, FALSE);
	add_keepflag(a, markup);
	after = count_keep(a);
	sa(&a, FALSE);
	add_keepflag(a, markup);
	return (after > before);
}

int	count_keep(t_node *a)
{
	int	flags_n;

	flags_n = 0;
	while (a)
	{
		if (a->keep == TRUE)
			flags_n += 1;
		a = a->next;
	}
	return (flags_n);
}

static int	has_false(t_node *a)
{
	while (a)
	{
		if (a->keep == FALSE)
			return (TRUE);
		a = a->next;
	}
	return (FALSE);
}

void	apply_keepflag(t_node **a, t_node **b, int markup)
{
	t_node	*copy;

	while (!stack_sorted(*a))
	{
		add_keepflag(*a, markup);
		while (has_false(*a))
		{
			copy = copy_stack(*a);
			if (sa_better(copy, markup))
				sa(a, TRUE);
			else if ((*a)->keep == FALSE
				&& stack_sizeof(a) > 3)
				pb(a, b, TRUE);
			else
				ra(a, TRUE);
			clean_stack(&copy);
			if (stack_sorted(*a))
				break ;
		}
		if (!has_false(*a) && !stack_sorted(*a))
			ra(a, TRUE);
	}
}
