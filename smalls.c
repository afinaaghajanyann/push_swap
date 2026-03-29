/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smalls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larevsha <larevsha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 20:06:40 by larevsha          #+#    #+#             */
/*   Updated: 2026/03/28 21:28:14 by larevsha         ###   ########.fr       */
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
		sa(a, opers);
	else if (first > second && second > third)
	{
		sa(a, opers);
	}
	else if (first > second && second < third && first > third)
		ra(a, opers);
	else if (first < second && second > third && first < third)
	{
		sa(a, opers);
		ra(a, opers);
	}
	else if (first < second && second > third && first > third)
		rra(a, opers);
}

//void	five(t_list **a, t_list **b, t_oper *opers)
//{
//	find_min(a, opers);
//	pb(a, b, opers);
//	find_min(a, opers);
//	pb(a, b, opers);
//	three(a, opers);
//	pa(a, b, opers);
//	pa(a, b, opers);
//}

//void	four(t_list **a, t_list **b, t_oper *opers)
//{
//	find_min(a, opers);
//	pb(a, b, opers);
//	three(a, opers);
//	pa(a, b, opers);
//}
