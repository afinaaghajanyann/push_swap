/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 18:37:35 by afaghaja          #+#    #+#             */
/*   Updated: 2026/03/27 16:04:59 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	indexavorel(t_list **a)
// {
// 	t_list	*tmp1;
// 	t_list	*tmp2;
// 	int		val;
// 	int		count;

// 	tmp1 = *a;
// 	while (tmp1)
// 	{
// 		tmp2 = *a;
// 		count = 0;
// 		val = tmp1->num;
// 		while (tmp2)
// 		{
// 			if (val > tmp2->num)
// 			{
// 				count++;
// 			}
// 			tmp2 = tmp2->next;
// 		}
// 		tmp1->index = count;
// 		tmp1 = tmp1->next;
// 	}
// }

int	find_the_element(t_list **b, int v)
{
	int		count;
	t_list	*temp;

	temp = *b;
	count = 0;
	while (temp)
	{
		if (temp->index < v)
			return (count);
		count++;
		temp = temp->next;
	}
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
			rb(b, opers);
			count--;
		}
	}
	else
	{
		count = size - count;
		while (count > 0)
		{
			rrb(b, opers);
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

void	basic(t_list **a, t_list **b, t_oper *opers)
{
	int		ind;
	t_list	*temp;

	indexavorel(a);
	while (*a)
	{
		temp = *a;
		ind = find_the_element(b, temp->index);
		rotate(b, ind, opers);
		pb(b, a, opers);
	}
	find_max(b, opers);
	while (*b)
		pa(a, b, opers);
}
