/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_markup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selow <selow@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:52:25 by selow             #+#    #+#             */
/*   Updated: 2025/09/30 16:48:25 by selow            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	assign_index_sorted(t_node *stack)
{
	t_node	*tmp;
	int		i;

	tmp = stack;
	i = 0;
	while (tmp)
	{
		tmp->index = i++;
		tmp = tmp->next;
	}
}

void	index_stack(t_node *reference, t_node *stack)
{
	t_node	*cur;
	t_node	*ref;

	if (!reference || !stack)
		return ;
	assign_index_sorted(reference);
	cur = stack;
	while (cur)
	{
		ref = reference;
		while (ref)
		{
			if (cur->content == ref->content)
			{
				cur->index = ref->index;
				break ;
			}
			ref = ref->next;
		}
		cur = cur->next;
	}
}
