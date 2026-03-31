/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 20:11:31 by larevsha          #+#    #+#             */
/*   Updated: 2026/03/31 21:12:32 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	turning_lines(t_list **a, t_list **b, char *s)
{
	int	len;

	len = ft_strlen(s);
	if (!s)
		return (0);
	if (s[len - 1] == '\n')
		s[len - 1] = '\0';
	if (!oper_use_s(a, b, s) || !oper_use_p(a, b, s) || !oper_use_r(a, b, s)
		|| !oper_use_rr(a, b, s))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}

void	gnl_logic(t_list **a, t_list **b)
{
	char	*s;

	while (1)
	{
		s = get_next_line(0);
		if (!s)
			break ;
		if (!turning_lines(a, b, s))
		{
			free(s);
			return ;
		}
		free(s);
	}
}

void	checker(t_list **a, t_list **b)
{
	gnl_logic(a, b);
	if (is_val_hertakanutyun(a, b))
		write(1, "OK/n", 3);
	else
		write(1, "KO/n", 3);
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
	checker(&v->a, &v->b);
	return (last_clean(&v->a, &v->b, v), 0);
}
