/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_funcs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:43:36 by afaghaja          #+#    #+#             */
/*   Updated: 2026/03/31 21:16:55 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a, t_oper *opers, int n)
{
	t_list	*temp;

	if (!a || !(*a) || !(*a)->next)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
	if (!n)
	{
		write(1, "sa\n", 3);
		opers->sa++;
	}
}

void	sb(t_list **a, t_oper *opers, int n)
{
	t_list	*temp;

	if (!a || !(*a) || !(*a)->next)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
	if (!n)
	{
		write(1, "sb\n", 3);
		opers->sb++;
	}
}

void	ss(t_list **a, t_list **b, t_oper *opers, int n)
{
	t_list	*temp1;
	t_list	*temp2;

	if (!a || !(*a) || !(*a)->next)
		return ;
	if (!b || !(*b) || !(*b)->next)
		return ;
	temp1 = *a;
	*a = (*a)->next;
	temp1->next = (*a)->next;
	(*a)->next = temp1;
	temp2 = *b;
	*b = (*b)->next;
	temp2->next = (*b)->next;
	(*b)->next = temp2;
	if (!n)
	{
		write(1, "ss\n", 3);
		opers->ss++;
	}
}
