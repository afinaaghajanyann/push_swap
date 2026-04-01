/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 20:11:31 by larevsha          #+#    #+#             */
/*   Updated: 2026/04/01 18:56:57 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	valueing(t_bench *count, t_oper *opers, t_list **a, t_list **b)
{
	opers->sa = 0;
	opers->sb = 0;
	opers->ss = 0;
	opers->pa = 0;
	opers->pb = 0;
	opers->ra = 0;
	opers->rb = 0;
	opers->rr = 0;
	opers->rra = 0;
	opers->rrb = 0;
	opers->rrr = 0;
	count->simple = 0;
	count->medium = 0;
	count->complex = 0;
	count->adaptive = 0;
	count->bench = 0;
	*a = NULL;
	*b = NULL;
}

int	turning_lines(t_list **a, t_list **b, char *s, t_oper *opers)
{
	int	len;

	len = ft_strlen(s);
	if (!s)
		return (0);
	if (len > 0 && s[len - 1] == '\n')
		s[len - 1] = '\0';
	if (s[0] == '\0')
		return (1);
	if (!oper_use_s(a, b, s, opers) && !oper_use_p(a, b, s, opers)
		&& !oper_use_r(a, b, s, opers) && !oper_use_rr(a, b, s, opers))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

void	gnl_logic(t_list **a, t_list **b, t_oper *opers)
{
	char	*s;

	while (1)
	{
		s = get_next_line(0);
		if (!s)
			break ;
		if (!turning_lines(a, b, s, opers))
		{
			free(s);
			get_next_line(-1);
			return ;
		}
		free(s);
	}
}

void	checker(t_list **a, t_list **b, t_oper *opers)
{
	gnl_logic(a, b, opers);
	if (is_val_hertakanutyun(a, b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_vals	*v;

	if (argc < 2)
		return (0);
	v = malloc(sizeof(t_vals));
	if (!v)
		cleaning(v);
	valueing(&v->count, &v->opers, &v->a, &v->b);
	v->a = lists(parsing(fill(argv, 1, v), &v->size, v), &v->size, v);
	checker(&v->a, &v->b, &v->opers);
	return (last_clean(&v->a, &v->b, v), 0);
}
