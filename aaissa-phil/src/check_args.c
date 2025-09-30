/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaissa <aaissa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:18:05 by aaissa            #+#    #+#             */
/*   Updated: 2025/08/16 20:20:06 by aaissa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_num(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_arguments(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_num(argv[i]))
			return (printf("Error: Provide numeric arguments .\n"), 1);
		i++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

int	validate_arguments(t_args *args, int argc)
{
	if (args->t_to_die < 1 || args->t_to_eat < 1 || args->t_to_sleep < 1)
		return (printf("Error: Times values must be at least 1 ms.\n"), 1);
	if (args->philos_nb > 200 || args->philos_nb <= 0)
		return (printf("Error:philos nb must be between 1 and 200\n"), 1);
	if (args->t_to_die > INT_MAX
		|| args->t_to_eat > INT_MAX
		|| args->t_to_sleep > INT_MAX
		|| (argc == 6 && (args->must_eat_count <= 0
				|| args->must_eat_count > INT_MAX)))
		return (printf("Error: Args must not exceed INT_MAX\n"), 1);
	return (0);
}
