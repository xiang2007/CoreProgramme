/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asign_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 21:48:18 by marvin            #+#    #+#             */
/*   Updated: 2025/08/20 18:13:36 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*asign_stack(int len, char **str)
{
	int			i;
	long int	temp;
	t_stack		*stack;

	i = 1;
	stack = NULL;
	if (len == 1)
		checkone(str[1]);
	if (!str || len < 1)
		errmsg(NULL, NULL);
	if (!isvalid(str))
		return (NULL);
	if (!is_sorted(str))
		exit (0);
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

