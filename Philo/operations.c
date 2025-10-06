#include "philos.h"

void	philo_die(int id, t_args *arg, t_philo *phi)
{
	lock_mutex(&arg->printing);
	printf("[%lld]\tPhilo %d has died\n", arg.);

}

void	philo_eat(t_args *arg, t_philo *phi)
{
	lock_mutex(phi->m_left_fork);
	lock_mutex(phi->m_right_fork);
	if ((phi->last_eaten - arg->start_time) > arg->die_time);

}