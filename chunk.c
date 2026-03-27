/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 17:54:15 by afaghaja          #+#    #+#             */
/*   Updated: 2026/03/27 16:35:10 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexavorel(t_list **a)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		val;
	int		count;

	tmp1 = *a;
	while (tmp1)
	{
		tmp2 = *a;
		count = 0;
		val = tmp1->num;
		while (tmp2)
		{
			if (val > tmp2->num)
			{
				count++;
			}
			tmp2 = tmp2->next;
		}
		tmp1->index = count;
		tmp1 = tmp1->next;
	}
}

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
	int pushed;

	limit = size;
	pushed = 0;
	while (*a)
	{
		if ((*a)->index < limit)
		{
			pb(b, a, opers);
			pushed++;
			if (pushed == limit)
				limit += size;
		}
		else
			ra(a, opers);
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
		pa(a, b, opers);
	}
}
