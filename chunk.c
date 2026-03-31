/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:54:15 by afaghaja          #+#    #+#             */
/*   Updated: 2026/03/31 16:12:49 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunk_size(t_list **a)
{
	int	size;
	int	len;

	size = 0;
	len = ft_lstsize(*a);
	while (size * size < len)
		size++;
	return (size);
}

void	push_chunk(t_list **a, t_list **b, int size, t_oper *opers)
{
	int	limit;
	int	pushed;
	int	j;

	limit = size;
	pushed = 0;
	while (*a)
	{
		j = ft_lstsize(*a);
		while (j-- > 0 && *a)
		{
			if ((*a)->index < limit)
			{
				pb(b, a, opers, 0);
				if ((*b)->index < limit - (size / 2))
					rb(b, opers, 0);
				pushed++;
				if (pushed >= limit)
					limit += size;
			}
			else
				ra(a, opers, 0);
		}
		limit += size;
	}
}

void	chunk(t_list **a, t_list **b, t_oper *opers)
{
	int	size;

	indexavorel(a);
	size = chunk_size(a);
	push_chunk(a, b, size, opers);
	while (*b)
	{
		find_max(b, opers);
		pa(a, b, opers, 0);
	}
}
