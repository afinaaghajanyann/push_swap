/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_funcs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:41:12 by afaghaja          #+#    #+#             */
/*   Updated: 2026/04/01 17:58:48 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a, t_oper *opers, int n)
{
	t_list	*first;
	t_list	*last;

	if (!a || !(*a) || !(*a)->next)
		return ;
	first = *a;
	last = ft_lstlast(first);
	*a = first->next;
	last->next = first;
	first->next = NULL;
	if (!n)
		write(1, "ra\n", 3);
	opers->ra++;
}

void	rb(t_list **a, t_oper *opers, int n)
{
	t_list	*first;
	t_list	*last;

	if (!a || !(*a) || !(*a)->next)
		return ;
	first = *a;
	last = ft_lstlast(first);
	*a = first->next;
	last->next = first;
	first->next = NULL;
	if (!n)
		write(1, "rb\n", 3);
	opers->rb++;
}

void	rr(t_list **a, t_list **b, t_oper *opers, int n)
{
	t_list	*first;
	t_list	*last;
	t_list	*first2;
	t_list	*last2;

	if (!a || !(*a) || !(*a)->next)
		return ;
	first = *a;
	last = ft_lstlast(first);
	*a = first->next;
	last->next = first;
	first->next = NULL;
	if (!b || !(*b) || !(*b)->next)
		return ;
	first2 = *b;
	last2 = ft_lstlast(first2);
	*b = first2->next;
	last2->next = first2;
	first2->next = NULL;
	if (!n)
		write(1, "rr\n", 3);
	opers->rr++;
}
