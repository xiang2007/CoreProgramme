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

void	philo_eat(int id, t_args *arg, t_philo *phi)
{
	t_ll	current_time;

	current_time = gettime();
	lock_mutex(&phi->m_left_fork[id - 1]);
	lock_mutex(&phi->m_right_fork[id + 1]);
	lock_mutex(&arg->execute);
	if ((phi->last_eaten - arg->start_time) > arg->die_time)
	{
		philo_die(current_time, id, arg, phi);
		return ;
	}
	else
	{
		arg->fork[id - 1] = 0;
		arg->fork[id + 1] = 0;
	}

}

