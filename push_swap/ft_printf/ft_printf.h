/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 18:37:31 by marvin            #+#    #+#             */
/*   Updated: 2025/06/10 18:37:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define LOWHEX "0123456789abcdef"
# define UPHEX "0123456789ABCDEF"

int		ft_putchar(int c);
size_t	ft_strlen(const char *str);
int		ft_putstr(const char *c);
char	*ft_itoa(unsigned int n);
int		ft_putnbr(long nbr);
int		ft_count(unsigned long n, int base);
int		ft_putui(unsigned int nbr);
int		ft_signs(char signs, va_list args);
int		ft_printvoid(void *ptr);
int		ft_puthex(unsigned long nbr, int flag);
int		ft_printf(const char *format, ...);
char	*ft_strdup(const char *str);

#endif