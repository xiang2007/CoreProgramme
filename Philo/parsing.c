#include "philos.h"

void	parse(int ac, char **av, t_args *ag)
{
	ag->num_o_phi = ft_atoi(av[1]);
	ag->die_time = ft_atoi(av[2]);
	ag->eat_time = ft_atoi(av[3]);
	ag->sleep_time = ft_atoi(av[4]);
	if (ac == 4)
		ag->must_eat = -1	;
	else
		ag->must_eat = ft_atoi(av[5]);
}

int	check_args(t_args *ag, int ac)
{
	if (ag->die_time < 1 || ag->eat_time < 1 || ag->sleep_time < 1)
		return (printf("Error: Time value must be higher than 1ms\n"), 1);
	if (ag->die_time > INT_MAX || ag->eat_time > INT_MAX 
		|| ag->sleep_time > INT_MAX);
		return (printf("Error: Time value must smaller than INT_MAX\n"), 1);
	if (ag->num_o_phi > 200 || ag->num_o_phi < 0)
		return (pritnf("Error: "))
}