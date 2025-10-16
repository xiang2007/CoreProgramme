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
	pthread_mutex_t	execute;
	pthread_mutex_t	print;
	pthread_mutex_t	die;
}					t_args;

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				died;
	int				meals_eaten;
	t_2l			last_eaten;
	t_2l			last_sleep;
	pthread_mutex_t	time;
	pthread_mutex_t	eat;
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
void	p_routine(t_args *ag, t_philo *phi);
t_philo	*init_philos(t_args *arg);
void	start_philo(t_args *ag, t_philo *philo);
t_philo	*parse(int ac, char **av, t_args *ag);
int	monitor_thread(t_args *ag, t_philo *phi);

#endif