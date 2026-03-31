/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_funcs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:44:35 by afaghaja          #+#    #+#             */
/*   Updated: 2026/03/31 21:21:26 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a, t_list **b, t_oper *opers, int n)
{
	t_list	*temp;

	if (!a || !b || !*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = NULL;
	ft_lstadd_front(a, temp);
	if (!n)
		write(1, "pa\n", 3);
	opers->pa++;
}

void	pb(t_list **b, t_list **a, t_oper *opers, int n)
{
	t_list	*temp;

	if (!a || !b || !*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = NULL;
	ft_lstadd_front(b, temp);
	write(1, "pb\n", 3);
	opers->pb++;
}
