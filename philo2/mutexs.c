/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 20:41:24 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/10/14 20:45:29 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philos.h"

void	lock_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_lock(mutex) != 0)
	{
		printf("Error locking mutex\n");
		return ;
	}
	
}

void	unlock_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_unlock(mutex) != 0)
	{
		printf("Error unlocking mutex\n");
		return ;
	}
}

void	destroy_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_destroy(mutex) != 0)
	{
		printf("Error destroying mutex\n");
		return ;
	}
}