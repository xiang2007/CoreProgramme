/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 18:32:43 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/06/16 11:29:57 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_signs(char signs, va_list args)
{
	if (!signs)
		return (0);
	if (signs == 'c')
		return (ft_putchar(va_arg(args, char)));
	if (signs == 'd' || signs == 'i')
		return (ft_putint(va_arg(args, int)));
	if (signs == 'u')
		return (ft_putdec(va_arg(args, unsigned int)));
	if (signs == 'x')
		return (ft_puthex(va_arg(args, unsigned int),1));
	if (signs == 'X')
		return (ft_puthex(va_arg(args, unsigned int),2));
	if (signs == 'p')
		return (ft_printvoid(va_arg(args, void *)));
	if (signs == '%')
		return (ft_putchar('%'));
}