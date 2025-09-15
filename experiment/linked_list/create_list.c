/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 00:50:24 by marvin            #+#    #+#             */
/*   Updated: 2025/06/27 00:50:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct Node *create_list(int data)
{
	struct Node *newnode = (struct Node *)malloc(sizeof(struct Node));
	newnode->data = data;
	newnode->next = NULL;
	return (newnode);
}
 