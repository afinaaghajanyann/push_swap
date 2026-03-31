/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smalls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 20:06:40 by larevsha          #+#    #+#             */
/*   Updated: 2026/03/31 16:16:19 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three(t_list **a, t_oper *opers)
{
	int	first;
	int	second;
	int	third;

	first = (*a)->num;
	second = (*a)->next->num;
	third = (*a)->next->next->num;
	if (first > second && second < third && first < third)
		sa(a, opers, 0);
	else if (first > second && second > third)
	{
		sa(a, opers, 0);
		rra(a, opers, 0);
	}
	else if (first > second && second < third && first > third)
		ra(a, opers, 0);
	else if (first < second && second > third && first < third)
	{
		sa(a, opers, 0);
		ra(a, opers, 0);
	}
	else if (first < second && second > third && first > third)
		rra(a, opers, 0);
}

void	five(t_list **a, t_list **b, t_oper *opers)
{
	find_min(a, opers);
	pb(b, a, opers, 0);
	find_min(a, opers);
	pb(b, a, opers, 0);
	three(a, opers);
	pa(a, b, opers, 0);
	pa(a, b, opers, 0);
}

void	four(t_list **a, t_list **b, t_oper *opers)
{
	find_min(a, opers);
	pb(b, a, opers, 0);
	three(a, opers);
	pa(a, b, opers, 0);
}

void	two(t_list **a, t_oper *opers)
{
	ra(a, opers, 0);
}
