#ifndef PHILOS_H
# define PHILOS_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>
# include <unistd.h>

typedef long long t_2l;

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
	long long	start_time;
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
	int	died;
	int	meals_eaten;
	t_2l	last_eaten;
	t_2l	last_sleep;
}				t_philo;

int	ft_atoi(const char *str);
int	ft_isalnum(int num);
t_2l gettime(void);
int	checknums(char **av);

#endif