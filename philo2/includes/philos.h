#ifndef PHILOS_H
# define PHILOS_H

# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <limits.h>
# include <unistd.h>

typedef long long t_2l;

typedef struct s_args
{
	int				num_o_phi;
	int				die_time;
	int				eat_time;
	int				sleep_time;
	int				must_eat;
	int				all_satisfied;
	int				stop;
	long long		start_time;
	pthread_mutex_t	*fork;
	pthread_mutex_t	m_meal;
	pthread_mutex_t	m_die;
	pthread_mutex_t	m_print;
}					t_args;

typedef struct s_philo
{
	int				id;
	int				finished;
	int				died;
	int				left_fork;
	int				right_fork;
	int				meals_eaten;
	t_2l			last_eaten;
	pthread_t		thread_id;
	t_args			*arg;
}					t_philo;

typedef struct s_philo_data
{
	t_args	*ag;
	t_philo	*philo;
}			t_philo_data;

int		ft_atoi(const char *str);
int		ft_isalnum(int num);
t_2l	gettime(void);
void	destroy_mutex(pthread_mutex_t *mutex);
void	unlock_mutex(pthread_mutex_t *mutex);
void	lock_mutex(pthread_mutex_t *mutex);
void	*p_routine(void *philo);
t_philo	*init_philos(t_args *arg);
int		start_philo(t_args *ag, t_philo *philo);
t_philo	*parse(int ac, char **av, t_args *ag);
int		start_monitor(t_philo *philo);
void	print(t_philo *philo, char *message);
void	cleanup(t_args *ag, t_philo *philo);

#endif