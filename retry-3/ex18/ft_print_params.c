/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:52:35 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/10/13 16:55:56 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar (char c);

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return ;
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac > 1)
	{
		while (i < ac)
		{
			ft_putstr(av[i]);
			ft_putchar('\n');
			i++;
		}
	}
	return (0);
}
