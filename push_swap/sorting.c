/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 21:49:02 by marvin            #+#    #+#             */
/*   Updated: 2025/08/19 21:49:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;
	int size;

	if (!stack || !*stack || !(*stack)->next)
		return;
	size = stacksize((*stack));
	a = (*stack)->value;
	b = (*stack)->next->value;
	if (size == 3)
	{
		c = (*stack)->next->next->value;
		if (a > b && a > c)
			ra(stack);
		if (b > a && b > c)
			rra(stack);
	}
	a = (*stack)->value;
	b = (*stack)->next->value;
	if (a > b)
		sa(stack);
}
