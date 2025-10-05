/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:14:53 by aaissa            #+#    #+#             */
/*   Updated: 2025/10/05 18:07:22 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h> 

typedef struct s_args
{
	int				philos_nb;
	long			t_to_die;
	long			t_to_eat;
	long			t_to_sleep;
	int				must_eat_count;
	int				is_died;
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	meal_mutex;
	int				all_satisfied;
	int				stop_threads;
}	t_args;

typedef struct s_philo
{
	int			id;
	int			l_fork;
	int			r_fork;
	long		last_meal_time;
	int			meals_eaten;
	int			finish_meals;
	pthread_t	thread_id;
	t_args		*args;
}	t_philos;

/* =========  Intitializer  ========= */

int		init_args(t_args *args, int ac, char **av);
int		init_forks(t_args *args);
int		init_global_mutexes(t_args *args);
int		init_philo(t_philos **philo, t_args *args);
int		initializer(t_args *args, t_philos **philos, int ac, char **av);

/* ========  Arguments check  ========= */

int		check_arguments(int ac, char **av);
int		validate_arguments(t_args *args, int ac);
int		ft_atoi(const char *str);

/* =========  Routine  ========= */

void	eat(t_philos *philo);
void	sleep_think(t_philos *philo);
void	handle_one_philo(t_philos *philo);
void	philo_life_cycle(t_philos *philo);
void	*routine(void *arg);

/* =========  monitor  ========= */

int		monitor(t_args *args, t_philos *philo);
int		check_death(t_philos *philo);
int		check_philos(t_philos *philo);
void	*monitor_routine(void *arg);

/* ========= Mutex utils ========= */

void	lock(pthread_mutex_t *mutex);
void	unlock(pthread_mutex_t *mutex);
void	destroy_fork_mutexes(t_args *args);
void	destroy_global_mutexes(t_args *args);

/* ========= Utils ========= */

long	get_current_time(void);
void	ft_usleep(long time_in_ms);
void	print(t_philos *philo, char *message);
void	clean_up(t_args *args, t_philos *philo);

#endif
