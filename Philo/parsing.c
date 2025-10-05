#include "philos.h"

int	is_num(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (-1);
	}
	return (0);
}

int	parse(int ac, char **av, t_args *ag)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (is_num(av[i]) == 0)
			i++;
		else
			return (-1);
	}
	ag->num_o_phi = ft_atoi(av[1]);
	ag->die_time = ft_atoi(av[2]);
	ag->eat_time = ft_atoi(av[3]);
	ag->sleep_time = ft_atoi(av[4]);
	if (ac == 5)
		ag->must_eat = -1;
	else
		ag->must_eat = ft_atoi(av[5]);
	if (check_args(ag, ac))
		return (-1);
	return (0);
}

int	check_args(t_args *ag, int ac)
{
	if (ag->die_time < 1 || ag->eat_time < 1 || ag->sleep_time < 1)
		return (printf("Error: Time value must be higher than 1ms\n"), 1);
	if (ag->die_time > INT_MAX || ag->eat_time > INT_MAX 
		|| ag->sleep_time > INT_MAX)
		return (printf("Error: Time value must smaller than INT_MAX\n"), 1);
	if (ag->num_o_phi > INT_MAX || ag->num_o_phi < 0)
		return (printf("Error: Number of philo must be between 1 and INT_MAX\n"), 1);
	if (((ac == 6) && ag->must_eat <= 0) || ag->must_eat > INT_MAX)
		return (printf("Error: Number must eat must be between 1 and INT_MAX"), 1);
	else
		return (0);
}

int	asign(int ac, char **av, t_args *ag)
{
	if (ac < 5 || ac > 6)
		return (printf("Invalid input 🥀\n"));
	if (parse(ac, av, ag) < 0)
		return (-1);
	ag->start_time = gettime();
	return (0);
}
