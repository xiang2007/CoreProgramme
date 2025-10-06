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

void	destroy_all_mutex(t_philo *phi)
{
	if(pthread_mutex_destroy(phi->m_left_fork) != 0)
	{
		printf("Error destroying left fork mutexn\n");
		exit (1);
	}
	if (pthread_mutex_destroy(phi->m_right_fork) != 0)
	{
		printf("Error destroying right fork mutex\n");
		exit (1);
	}
}