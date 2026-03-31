/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larevsha <larevsha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 17:39:59 by larevsha          #+#    #+#             */
/*   Updated: 2026/03/30 19:16:36 by larevsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include "push_swap.h"

int	cycle(int i, const char *str, va_list list)
{
	int	count;

	count = 0;
	if (str[i + 1] == 'c')
		count += ft_putchar(va_arg(list, int), 2);
	else if (str[i + 1] == 'd' || str[i + 1] == 'i')
		count += ft_putnbr_printf(va_arg(list, int), 2);
	else if (str[i + 1] == 's')
		count += ft_putstr_printf(va_arg(list, char *), 2);
	else if (str[i + 1] == 'p')
		count += ft_putad(va_arg(list, void *), 2);
	else if (str[i + 1] == 'u')
		count += ft_putunint(va_arg(list, unsigned int), 2);
	else if (str[i + 1] == '%')
		count += ft_putperc(2);
	else if (str[i + 1] == 'x')
		count += ft_putx(va_arg(list, unsigned int), 2);
	else if (str[i + 1] == 'X')
		count += ft_putxx(va_arg(list, unsigned int), 2);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		count;

	va_start(list, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			write(2, &str[i], 1);
			count++;
		}
		else if (str[i + 1] != 0)
		{
			count += cycle(i, str, list);
			i++;
		}
		i++;
	}
	va_end(list);
	return (count);
}
