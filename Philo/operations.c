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

void	philo_eat(t_args *arg, t_philo *phi)
{
	lock_mutex(phi->m_left_fork);
	lock_mutex(phi->m_right_fork);
	lock_mutex(&arg->printing);
	lock_mutex(&arg->execute);
	if ((phi->last_eaten - arg->start_time) > arg->die_time);

}