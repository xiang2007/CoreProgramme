#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>
# include "../utils/utils.h"

typedef struct	s_args
{
	int	num_o_phi;
	int	die_time;
	int	eat_time;
	int	sleep_time;
	int	must_eat;
}				t_args;

typedef struct	s_philo
{
	int	died;
	int	eaten;
	int	thinking;
	int	sleeping;
}				t_philo;

#endif