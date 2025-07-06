/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 00:50:24 by marvin            #+#    #+#             */
/*   Updated: 2025/07/06 12:34:24 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list *ft_lstnew(void *content)
{
	t_list newnode;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	return (newnode);
}
 