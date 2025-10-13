#include "philos.h"

void	philo_die(t_ll c_time, int id, t_args *arg, t_philo *phi)
{
	lock_mutex(&arg->printing);
	lock_mutex(&arg->die);
	printf("[%lld]\tPhilo %d has died\n", c_time, id);
	arg->stop = 1;
	phi[id].died = 1;
	unlock_mutex(&arg->printing);
	unlock_mutex(&arg->die);
	return ;

}

void	philo_eat(int id, t_args *arg, t_philo *philo)
{
	if (id % 2 == 0)
	{
		lock_mutex(philo[id].m_left_fork);
		printf("Philo %d takes fork", id);
		lock_mutex(philo[id].m_right_fork);
		printf("Philo %d takes fork", id);
	}
	else
	{
		lock_mutex(philo[id].m_right_fork);
		printf("Philo %d takes fork", id);
		lock_mutex(philo[id].m_left_fork);
		printf("Philo %d takes fork", id);
	}
	philo->last_eaten = gettime();
	philo->meals_eaten++;
	printf("Philo %d eating", id);
	unlock_mutex(philo[id].m_left_fork);
	unlock_mutex(philo[id].right_fork);
}

void	philo_sleep_think(int id, t_args *arg, t_philo philo)
{
	lock_mutex(&arg->execute);
	printf("Philo %d is sleeping ZZZ", id);
	usleep(ms_to_us(arg->sleep_time));
	printf("Philo %d is thinking", id);
	usleep(ms_to_us(arg.))
}
 