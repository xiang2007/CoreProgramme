/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 21:48:26 by marvin            #+#    #+#             */
/*   Updated: 2025/08/21 12:11:42 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	errmsg(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !*stack_a)
		ft_lstclear(stack_a);
	if (!stack_b || !*stack_b)
		ft_lstclear(stack_b);
	write(2, "Error\n", 6);
	exit (1);
}
