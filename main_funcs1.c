/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_funcs1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larevsha <larevsha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 21:29:46 by lyov              #+#    #+#             */
/*   Updated: 2026/03/30 19:27:28 by larevsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_all(t_bench *count)
{
	return (count->simple + count->medium + count->complex + count->adaptive
		+ count->bench);
}

int	bench_pars(char **argv, t_bench *count, int argc)
{
	int	i;

	i = 0;
	while (++i <= 2 && i < argc)
	{
		if (ft_strncmp(argv[i], "--simple", 9) == 0)
			(count->simple)++;
		else if (ft_strncmp(argv[i], "--medium", 9) == 0)
			(count->medium)++;
		else if (ft_strncmp(argv[i], "--complex", 10) == 0)
			(count->complex)++;
		else if (ft_strncmp(argv[i], "--adaptive", 11) == 0)
			(count->adaptive)++;
		else if (ft_strncmp(argv[i], "--bench", 8) == 0)
			(count->bench)++;
		if (!(count->simple + count->medium + count->complex + count->adaptive
				+ count->bench))
			return (0);
	}
	if (count->simple + count->medium + count->complex
		+ count->adaptive == 2 || count->bench == 2)
		return (-1);
	if (add_all(count) == 2)
		return (2);
	return (1);
}

int	start_point(int pars, t_list **a, t_list **b, t_vals *vals)
{
	int	i;

	i = 0;
	if (pars == -1)
	{
		ft_lstclear(a, NULL);
		ft_lstclear(b, NULL);
		cleaning(vals);
	}
	else if (pars == 0)
		i = 1;
	else if (pars == 1)
		i = 2;
	else if (pars == 2)
		i = 3;
	return (i);
}

int	method(t_bench *count)
{
	int	alg;

	alg = 0;
	if (count->bench == 1)
		alg = 10;
	if (count->simple == 1)
		alg += 1;
	else if (count->medium == 1)
		alg += 2;
	else if (count->complex == 1)
		alg += 3;
	else if (count->adaptive == 1)
		alg += 4;
	return (alg);
}

void	start_sort(t_list **a, t_list **b, int alg, t_oper *opers)
{
	if (alg == 1 || alg == 11)
		basic(a, b, opers);
	else if (alg == 2 || alg == 12)
		chunk(a, b, opers);
	else if (alg == 3 || alg == 13)
		radix(a, b, opers);
}
