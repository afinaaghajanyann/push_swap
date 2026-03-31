/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counts1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyov <lyov@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/19 14:03:46 by larevsha          #+#    #+#             */
/*   Updated: 2026/03/29 23:26:24 by lyov             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putx(unsigned int a, int fd)
{
	int		i;
	char	c;

	i = 0;
	if (a >= 16)
		i += ft_putx(a / 16, 1);
	if ((a % 16) <= 9)
		c = (a % 16) + '0';
	else
		c = (a % 16) - 10 + 'a';
	write (fd, &c, 1);
	i++;
	return (i);
}

int	ft_putxx(unsigned int a, int fd)
{
	int		i;
	char	c;

	i = 0;
	if (a >= 16)
		i += ft_putxx(a / 16, 1);
	if ((a % 16) <= 9)
		c = (a % 16) + '0';
	else
		c = (a % 16) - 10 + 'A';
	write (fd, &c, 1);
	i++;
	return (i);
}

int	ft_putperc(int fd)
{
	write(fd, "%", 1);
	return (1);
}

int	ft_putchar(char c, int fd)
{
	write (fd, &c, 1);
	return (1);
}
