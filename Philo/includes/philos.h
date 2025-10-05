#ifndef PHILOS_H
# define PHILOS_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>
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
	int	fork;
	t_ll	start_time;
	pthread_mutex_t	execute;
	pthread_mutex_t printing	
}				t_args;

typedef struct	s_philo
{
	int	id;
	int	left_fork;
	int	right_fork;
	int	last_eaten;
	int	last_sleep;
	int	died;
	int	eaten;
	int	thinking;
	int	sleeping;
}				t_philo;

t_ll gettime(void);
int	check_args(t_args *ag, int ac);
int	asign(int ac, char **av, t_args *ag);

#endif