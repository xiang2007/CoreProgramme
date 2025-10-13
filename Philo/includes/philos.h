#ifndef PHILOS_H
# define PHILOS_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>
# include <unistd.h>
# include "../utils/utils.h"

typedef long long	t_ll;

typedef struct	s_args
{
	int	num_o_phi;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	must_eat;
	int	all_satisfied;
	int	*fork;
	int	stop;
	t_ll	start_time;
	pthread_mutex_t	execute;
	pthread_mutex_t	printing;
	pthread_mutex_t	die;
}				t_args;

typedef struct	s_philo
{
	int	id;
	int	left_fork;
	pthread_mutex_t	*m_left_fork;
	int	right_fork;
	pthread_mutex_t	*m_right_fork;
	int	last_eaten;
	int	last_sleep;
	int	died;
	int	eaten;
	int	thinking;
	int	sleeping;
	int	meals_eaten;
	t_ll	last_sleep;
}				t_philo;

t_ll	gettime(void);
int		check_args(t_args *ag, int ac);
int		asign(int ac, char **av, t_args *ag);
void	lock_mutex(pthread_mutex_t	*mutex);
void	unlock_mutex(pthread_mutex_t *mutex);
void	destroy_all_mutex(t_philo *phi);
int		ms_to_us(int ms);

#endif