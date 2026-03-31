/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 00:52:44 by lyov              #+#    #+#             */
/*   Updated: 2026/03/31 20:40:52 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	write_t_oper(t_oper *opers, int number, int total)
{
	if (number == 11)
		ft_printf("Simple / O(n^2)\n");
	else if (number == 12)
		ft_printf("Medium / O(n√n)\n");
	else if (number == 13)
		ft_printf("Complex / O(nlogn)\n");
	ft_printf("[bench] total_ops: %d\n", total);
	ft_printf("[bench] sa: %d sb: %d ss: %d pa: %d pb: %d\n",
		opers->sa, opers->sb, opers->ss, opers->pa, opers->pb);
	ft_printf("[bench] ra: %d rb: %d rr: %d rra: %d rrb: %d rrr: %d\n",
		opers->ra, opers->rb, opers->rr, opers->rra, opers->rrb, opers->rrr);
}

void	isbench(int alg, t_oper *opers, int number, float dis)
{
	int		total;
	int		rem;
	char	*s1;
	char	*s2;

	if (alg < 10)
		return ;
	total = opers->pa + opers->pb + opers->ra + opers->rb + opers->rra
		+ opers->rrb + opers->rrr + opers->sa;
	s1 = ft_itoa((int)dis);
	rem = return_rem(dis);
	s2 = ft_itoa(rem);
	if (rem < 10)
		ft_printf("[bench] disorder: %s.0%s%%\n", s1, s2);
	else
		ft_printf("[bench] disorder: %s.%s%%\n", s1, s2);
	free(s1);
	free(s2);
	ft_printf("[bench] strategy: ");
	write_t_oper(opers, number, total);
}

int	adaptive_check(int alg)
{
	if (alg == 4 || alg == 14
		|| alg == 0 || alg == 10)
		return (1);
	return (0);
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
	v->pars = bench_pars(argv, &v->count, argc);
	v->i = start_point(v->pars, &v->a, &v->b, v);
	v->alg = method(&v->count);
	v->a = lists(parsing(fill(argv, v->i, v), &v->size, v), &v->size, v);
	v->dis = disorder(&v->a);
	if (disorder(&v->a))
	{
		if (adaptive_check(v->alg))
			v->strat = custom(disorder(&v->a),
					&v->a, &v->b, &v->opers);
		start_sort(&v->a, &v->b, v->alg, &v->opers);
	}
	if (adaptive_check(v->alg))
		isbench(v->alg, &v->opers, v->strat, (v->dis) * 100);
	else
		isbench(v->alg, &v->opers, v->alg, (v->dis) * 100);
	return (last_clean(&v->a, &v->b, v), 0);
}
