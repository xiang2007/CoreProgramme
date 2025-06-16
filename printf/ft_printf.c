/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:18:44 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/06/15 12:01:47 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int	index;
	int	count;
	va_list args;
	va_start(args,format);
	
	index = 0;
	count = 0;
	while (format[index])
	{
		if (format[index] != '%')
		{
			write(1, &format[index], 1);
			index++;
			count++;
		}
		else if (format[index] == '%')
		{
			count += ft_signs(format[index + 1],args);
			index += 2;
		}
	}
	va_end(args);
	return (count);
}