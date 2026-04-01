/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:37:35 by afaghaja          #+#    #+#             */
/*   Updated: 2026/04/01 18:32:22 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_the_element(t_list **b, int v)
{
	int		count;
	int		closest;
	int		j;
	t_list	*temp;

	temp = *b;
	count = 0;
	j = 0;
	closest = -1;
	while (temp)
	{
		if (temp->index < v && temp->index > closest)
		{
			closest = temp->index;
			count = j;
		}
		temp = temp->next;
		j++;
	}
	if (closest == -1)
		count = -1;
	return (count);
}

void	rotate(t_list **b, int count, t_oper *opers)
{
	int	size;

	size = ft_lstsize(*b);
	if (count < size / 2)
	{
		while (count > 0)
		{
			rb(b, opers, 0);
			count--;
		}
	}
	else
	{
		count = size - count;
		while (count > 0)
		{
			rrb(b, opers, 0);
			count--;
		}
	}
}

void	find_max(t_list **b, t_oper *opers)
{
	t_list	*tmp_l;
	int		max;
	int		pos;
	int		count;

	if (!b || !*b)
		return ;
	tmp_l = *b;
	max = tmp_l->index;
	pos = 0;
	count = 0;
	while (tmp_l)
	{
		if (tmp_l->index > max)
		{
			max = tmp_l->index;
			pos = count;
		}
		count++;
		tmp_l = tmp_l->next;
	}
	rotate(b, pos, opers);
}

void	find_min(t_list **b, t_oper *opers)
{
	t_list	*tmp_l;
	int		min;
	int		pos;
	int		count;

	if (!b || !*b)
		return ;
	tmp_l = *b;
	min = tmp_l->num;
	pos = 0;
	count = 0;
	while (tmp_l)
	{
		if (tmp_l->num < min)
		{
			min = tmp_l->num;
			pos = count;
		}
		count++;
		tmp_l = tmp_l->next;
	}
	rotate_a(b, pos, opers);
}

void	basic(t_list **a, t_list **b, t_oper *opers)
{
	int		ind;
	int		size;
	t_list	*temp;

	indexavorel(a);
	while (*a)
	{
		temp = *a;
		size = ft_lstsize(*b);
		ind = find_the_element(b, temp->index);
		if (size > 0)
		{
			if (ind == -1)
				find_max(b, opers);
			else
				rotate(b, ind, opers);
		}
		pb(b, a, opers, 0);
	}
	find_max(b, opers);
	while (*b)
		pa(a, b, opers, 0);
}
