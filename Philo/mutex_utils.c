#include "philos.h"

void	lock_mutex(pthread_mutex_t	*mutex)
{
	if ((pthread_mutex_lock(mutex)) != 0)
	{
		printf("Error locking mutex\n");
		exit (1);
	}
}

void	unlock_mutex(pthread_mutex_t *mutex)
{
	if ((pthread_mutex_unlock(mutex)) != 0)
	{
		printf("Error unlocking mutex\n");
		exit (1);
	}
}

void	destroy_all_mutex(pthread_mutex_t *mutex)
{
	pthread_mutex_destroy(mutex->__align)
}