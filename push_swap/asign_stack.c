/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asign_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 21:48:18 by marvin            #+#    #+#             */
/*   Updated: 2025/08/19 21:48:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*asign_stack(int len, char **str)
{
	int	i;
	long int	temp;
	t_stack		*stack;

	i = 1;
	stack = NULL;
	if (!str || len <= 1)
		errmsg(NULL, NULL, "asignstack no str, len <= 1");
	if (!isvalid(str))
		errmsg(NULL, NULL, "not valid");
	while (i < len)
	{
		temp = ft_atoi(str[i]);
		if (stack == NULL)
				stack = ft_nodenew(temp, i);
		else
			ft_lstadd_back(&stack, ft_nodenew(temp, i));
		i++;
	}
	asign_pos(stack);
	return (stack);
}
