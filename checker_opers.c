/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_opers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 19:04:14 by afaghaja          #+#    #+#             */
/*   Updated: 2026/03/31 21:14:04 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	oper_use_s(t_list **a, t_list **b, char *s,)
{
	if (ft_strcmp(s, "sa"))
		sa(a, 1);
	else if (ft_strcmp(s, "sb"))
		sb(b, 1);
	else if (ft_strcmp(s, "ss"))
		ss(a, b, 1);
	else
		return (0);
	return (1);
}

int	oper_use_p(t_list **a, t_list **b, char *s)
{
	if (ft_strcmp(s, "pa"))
		pa(a, 1);
	else if (ft_strcmp(s, "pb"))
		pb(b, 1);
	else
		return (0);
	return (1);
}

int	oper_use_r(t_list **a, t_list **b, char *s)
{
	if (ft_strcmp(s, "ra"))
		ra(a, 1);
	else if (ft_strcmp(s, "rb"))
		rb(b, 1);
	else if (ft_strcmp(s, "rr"))
		rr(a, b, 1);
	else
		return (0);
	return (1);
}

int	oper_use_rr(t_list **a, t_list **b, char *s)
{
	if (ft_strcmp(s, "rra"))
		rra(a, 1);
	else if (ft_strcmp(s, "rrb"))
		rrb(b, 1);
	else if (ft_strcmp(s, "rrr"))
		rrr(a, b, 1);
	else
		return (0);
	return (1);
}
