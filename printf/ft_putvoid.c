/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putvoid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshou-xi <wshou-xi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 11:38:42 by wshou-xi          #+#    #+#             */
/*   Updated: 2025/06/16 11:23:14 by wshou-xi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printvoid(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
		return (ft_putstr("0x0"));
	count += ft_putstr("0x");
	count += ft_puthex((unsigned long)ptr,1);
	return (count);
}