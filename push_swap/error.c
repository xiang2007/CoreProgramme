/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 21:48:26 by marvin            #+#    #+#             */
/*   Updated: 2025/08/19 21:48:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	errmsg(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (!stack_a || !*stack_a)
		ft_lstclear(stack_a);
	if (!stack_b || !*stack_b)
		ft_lstclear(stack_b);
	ft_putstr("ERROR from ");
	ft_putstr(str);
	ft_putstr("\n");
	exit (1);
}