/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_opers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 19:04:14 by afaghaja          #+#    #+#             */
/*   Updated: 2026/04/01 17:57:17 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	oper_use_s(t_list **a, t_list **b, char *s, t_oper *opers)
{
	if (!ft_strcmp(s, "sa"))
		sa(a, opers, 1);
	else if (!ft_strcmp(s, "sb"))
		sb(b, opers, 1);
	else if (!ft_strcmp(s, "ss"))
		ss(a, b, opers, 1);
	else
		return (0);
	return (1);
}

int	oper_use_p(t_list **a, t_list **b, char *s, t_oper *opers)
{
	if (!ft_strcmp(s, "pa"))
		pa(a, b, opers, 1);
	else if (!ft_strcmp(s, "pb"))
		pb(b, a, opers, 1);
	else
		return (0);
	return (1);
}

int	oper_use_r(t_list **a, t_list **b, char *s, t_oper *opers)
{
	if (!ft_strcmp(s, "ra"))
		ra(a, opers, 1);
	else if (!ft_strcmp(s, "rb"))
		rb(b, opers, 1);
	else if (!ft_strcmp(s, "rr"))
		rr(a, b, opers, 1);
	else
		return (0);
	return (1);
}

int	oper_use_rr(t_list **a, t_list **b, char *s, t_oper *opers)
{
	if (!ft_strcmp(s, "rra"))
		rra(a, opers, 1);
	else if (!ft_strcmp(s, "rrb"))
		rrb(b, opers, 1);
	else if (!ft_strcmp(s, "rrr"))
		rrr(a, b, opers, 1);
	else
		return (0);
	return (1);
}
