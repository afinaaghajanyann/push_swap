/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 18:40:31 by afaghaja          #+#    #+#             */
/*   Updated: 2026/03/26 19:31:37 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len(int n)
{
	int		count;
	long	num;

	count = 0;
	num = n;
	if (num <= 0)
	{
		count = 1;
		num = -num;
	}
	while (num > 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*ptr;
	long long	num;
	int			count;

	num = n;
	count = len(n);
	ptr = malloc(sizeof(char) * (count + 1));
	if (!ptr)
		return (NULL);
	ptr[count] = '\0';
	if (num < 0)
	{
		ptr[0] = '-';
		num = -num;
	}
	if (n == 0)
		ptr[0] = '0';
	count--;
	while (num > 0)
	{
		ptr[count] = (num % 10) + '0';
		num = num / 10;
		count--;
	}
	return (ptr);
}
