/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   custom.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larevsha <larevsha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 16:27:32 by afaghaja          #+#    #+#             */
/*   Updated: 2026/03/30 19:29:47 by larevsha         ###   ########.fr       */
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

void	small_size(t_list **a, t_list **b, t_oper *opers)
{
	if (ft_lstsize(*a) == 3)
		three(a, opers);
	else if (ft_lstsize(*a) == 5)
		five(a, b, opers);
	else if (ft_lstsize(*a) == 4)
		four(a, b, opers);
	else if (ft_lstsize(*a) == 2)
		two(a, opers);
}

int	custom(float dis, t_list **a, t_list **b, t_oper *opers)
{
	if (ft_lstsize(*a) < 6)
	{
		small_size(a, b, opers);
		return (11);
	}
	else if (dis < 0.2)
	{
		basic(a, b, opers);
		return (11);
	}
	else if (dis >= 0.2 && dis < 0.5)
	{
		chunk(a, b, opers);
		return (12);
	}
	else if (dis >= 0.5)
	{
		radix(a, b, opers);
		return (13);
	}
	return (0);
}
