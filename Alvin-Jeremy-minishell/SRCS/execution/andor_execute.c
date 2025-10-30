/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   andor_execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchuah <jeremychuahtm@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 23:23:51 by jchuah            #+#    #+#             */
/*   Updated: 2025/10/26 00:00:51 by jchuah           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	andor_execute(t_andor *andor, t_shelldata *shelldata)
{
	int	return_val;

	return_val = execute_ast(andor->left, shelldata);
	if (return_val == ERFATAL)
		return (ERFATAL);
	if (andor->type == AND_IF)
	{
		if (return_val == 0)
			return (execute_ast(andor->right, shelldata));
		return (return_val);
	}
	else if (andor->type == OR_IF)
	{
		if (return_val != 0)
			return (execute_ast(andor->right, shelldata));
		return (return_val);
	}
	ft_putstr_fd("\"&& ||\" parse error\n", 2);
	return (255);
}
