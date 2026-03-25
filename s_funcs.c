/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_funcs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:43:36 by afaghaja          #+#    #+#             */
/*   Updated: 2026/03/25 14:44:03 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **a)
{
	t_list	*temp;

	if (!a || !(*a) || !(*a)->next)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
	write(1, "sa", 2);
	write(1, "\n", 1);
}

void	sb(t_list **a)
{
	t_list	*temp;

	if (!a || !(*a) || !(*a)->next)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = (*a)->next;
	(*a)->next = temp;
	write(1, "sb", 2);
	write(1, "\n", 1);
}

void	ss(t_list **a, t_list **b)
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
	write(1, "ss\n", 3);
}
