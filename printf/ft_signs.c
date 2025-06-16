/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:32:43 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/06/16 16:00:38 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_signs(char signs, va_list args)
{
	int count;

	count = 0;
	if (!signs)
		return (0);
	if (signs == 'c')
		count += (ft_putchar(va_arg(args, int)));
	if (signs == 'd' || signs == 'i')
		count += (ft_putnbr(va_arg(args, int)));
	if (signs == 'u')
		count += (ft_putdec(va_arg(args, unsigned int)));
	if (signs == 'x')
		count += (ft_puthex(va_arg(args, unsigned int),1));
	if (signs == 'X')
		count += (ft_puthex(va_arg(args, unsigned int),2));
	if (signs == 'p')
		count += (ft_printvoid(va_arg(args, void *)));
	if (signs == '%')
		count += (ft_putchar('%'));
	if (signs == 's')
		count += (ft_putstr(va_arg(args, char *)));
	
	return (count);
}