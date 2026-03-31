/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyov <lyov@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 20:03:03 by larevsha          #+#    #+#             */
/*   Updated: 2026/03/29 23:33:56 by lyov             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putnbr_printf(int n, int fd)
{
	char	a;
	int		i;

	i = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n != -2147483648 && n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		i++;
	}
	if (n >= 10)
		i += ft_putnbr_printf(n / 10, fd);
	a = (n % 10) + 48;
	write(fd, &a, 1);
	i++;
	return (i);
}

int	ft_putstr_printf(char *s, int fd)
{
	int	i;

	if (!s)
		return (write(fd, "(null)", 6), 6);
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	return (i);
}

static int	ft_putxad(unsigned long a, int fd)
{
	int		i;
	char	c;

	i = 0;
	if (a >= 16)
		i += ft_putxad(a / 16, 1);
	if ((a % 16) <= 9)
		c = (a % 16) + '0';
	else
		c = (a % 16) - 10 + 'a';
	write (fd, &c, 1);
	i++;
	return (i);
}

int	ft_putad(void *c, int fd)
{
	int				i;
	unsigned long	ad;

	if (!c)
		return (write(1, "(nil)", 5), 5);
	ad = (unsigned long)c;
	write (fd, "0x", 2);
	i = ft_putxad(ad, 1) + 2;
	return (i);
}

int	ft_putunint(unsigned int n, int fd)
{
	char	a;
	int		i;

	i = 0;
	if (n >= 10)
		i += ft_putnbr_printf(n / 10, fd);
	a = (n % 10) + 48;
	write(fd, &a, 1);
	i++;
	return (i);
}
