/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 16:27:32 by afaghaja          #+#    #+#             */
/*   Updated: 2026/03/25 16:29:41 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	disorder(t_list **a)
{
	float	mistakes;
	float	total_pairs;
	t_list	*i;
	t_list	*j;

	mistakes = 0;
	total_pairs = 0;
	i = *a;
	while (i)
	{
		j = i->next;
		while (j)
		{
			total_pairs++;
			if (i->num > j->num)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0);
	return (mistakes / total_pairs);
}

int	custom(float dis, t_list **a, t_list **b)
{
	if (dis < 0.2)
	{
		basic(a, b);
		return(1);
	}
	else if (dis >= 0.2 && dis < 0.5)
	{
		chunk(a, b);
		return(2);
	}
	else
	{
		radix(a, b);
		return(3);
	}
}
