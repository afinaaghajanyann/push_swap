/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 21:36:12 by larevsha          #+#    #+#             */
/*   Updated: 2026/03/29 19:36:45 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_value(int size)
{
	int	i;
	int	n;
	
	i = 0;
	n = size - 1;
	while (n > 0)
	{
		n /= 2;
		i++;
	}
	return (i);
}

void	radix(t_list **a, t_list **b, t_oper *opers)
{
	int	size;
	int	bit;
	int	bits;
	int	i;

	bit = 0;
	size = ft_lstsize(*a);
	indexavorel(a);
	bits = max_value(size);
	while (bit < bits)
	{
		i = 0;
		while (i < size)
		{
			if ((*a)->index >> bit & 1)
				ra(a, opers);
			else
				pb(b, a, opers);
			i++;
		}
		while (*b)
			pa(a, b, opers);
		bit++;
	}
}