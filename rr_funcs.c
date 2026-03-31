/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:42:19 by afaghaja          #+#    #+#             */
/*   Updated: 2026/03/31 21:15:19 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **a, t_oper *opers, int n)
{
	t_list	*last;
	t_list	*prev;

	if (!a || !*a || !(*a)->next)
		return ;
	prev = *a;
	last = ft_lstlast(*a);
	while ((prev->next)->next != NULL)
		prev = prev->next;
	prev->next = NULL;
	last->next = *a;
	*a = last;
	if (!n)
	{
		write(1, "rra\n", 4);
		opers->rra++;
	}
}

void	rrb(t_list **a, t_oper *opers, int n)
{
	t_list	*last;
	t_list	*prev;

	if (!a || !*a || !(*a)->next)
		return ;
	prev = *a;
	last = ft_lstlast(*a);
	while ((prev->next)->next != NULL)
		prev = prev->next;
	prev->next = NULL;
	last->next = *a;
	*a = last;
	if (!n)
	{
		write(1, "rrb\n", 4);
		opers->rrb++;
	}
}

void	rrr(t_list **a, t_list **b, t_oper *opers, int n)
{
	rra(a, opers, 1);
	rrb(b, opers, 1);
	if (!n)
	{
		write(1, "rrr\n", 4);
		opers->rrr++;
	}
}
