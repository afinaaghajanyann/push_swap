/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 14:42:19 by afaghaja          #+#    #+#             */
/*   Updated: 2026/03/25 14:42:54 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **a)
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
	write(1, "rra", 3);
	write(1, "\n", 1);
}

void	rrb(t_list **a)
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
	write(1, "rrb", 3);
	write(1, "\n", 1);
}

void	rrr(t_list **a, t_list **b)
{
	t_list	*last;
	t_list	*prev;
	t_list	*last2;
	t_list	*prev2;

	if (!a || !*a || !(*a)->next)
		return ;
	prev = *a;
	last = ft_lstlast(*a);
	while ((prev->next)->next != NULL)
		prev = prev->next;
	prev->next = NULL;
	last->next = *a;
	*a = last;
	if (!b || !*b || !(*b)->next)
		return ;
	prev2 = *b;
	last2 = ft_lstlast(*b);
	while ((prev2->next)->next != NULL)
		prev2 = prev2->next;
	prev2->next = NULL;
	last2->next = *b;
	*b = last2;
	write(1, "rrr\n", 4);
}
