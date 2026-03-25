/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 00:52:44 by lyov              #+#    #+#             */
/*   Updated: 2026/03/25 14:37:54 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	zero(t_bench *count, t_oper *opers)
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
	opers->total = opers->pa + opers->pb + opers->ra + opers->rb + opers->rra
		+ opers->rrb + opers->rrr + opers->sa;
	count->simple = 0;
	count->medium = 0;
	count->complex = 0;
	count->adaptive = 0;
	count->bench = 0;
}

int	bench_pars(char **argv, t_bench *count)
{
	int	i;

	i = 0;
	while (++i <= 2)
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
		if (!(count->simple + count->medium + count->complex
				+ count->adaptive + count->bench))
			return (0);
	}
	if (count->simple + count->medium + count->complex
		+ count->adaptive == 2 || count->bench == 2)
		return (-1);
	if (count->simple + count->medium + count->complex + count->adaptive
		+ count->bench == 2)
		return (2);
	return (1);
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

int	start_point(int pars)
{
	int	i;

	i = 0;
	if (pars == -1)
		exit_func(/*func*/);
	else if (pars == 0)
		i = 1;
	else if (pars == 1)
		i = 2;
	else if (pars == 2)
		i = 3;
	return (i);
}

void	start_sort(t_list *a, t_list *b, int alg, int size)
{
	//if (alg == 1 || alg == 11)
	//	simple(&a, &b);
	/*else*/ if (alg == 2 || alg == 12)
		chunk(a, b, size);
	else if (alg == 3 || alg == 13)
		radix(&a, &b);
	//else if (alg == 4 || alg == 14 || alg == 0)
	//	adaptive (&a, &b);
}

void	isbench(int alg, t_oper *opers, double disorder /*, Afini adaptivic stanumenq tiv*/)
{
	int	total;

	if (alg < 10)
		return ;
	/*taki sax algery Afini adaptivi return tvern en*/
	//write(2, "disorder: "&disorder, 5);
	write(2, "strategy: ", 11);
	if (alg == 11)
		write(2, "Simple / O(n^2)", 18);
	else if (alg == 11)
		write(2, "Adaptive / O(n√n))", 22);
	else if (alg == 12)
		write(2, "Complex / O(nlogn)", 19);
	write(2, "total_ops: ", 12);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_bench	count;
	t_oper	opers;
	int		alg;
	int		pars;
	int		i;
	int		size;
//dajy karanq alg jnjenq heto grenq vochte if alg < 10... ayl 
// if method(count) < 10

	b = NULL;
	zero(&count, &opers);
	pars = bench_pars(argv, &count);
	i = start_point(pars);
	alg = method(&count);
//talis enq Afini kodi mej 	fill(argv, i) vor ta inti zangvac
//	size = sizeof(/*Afini func*/) / sizeof(/*Afini func*/[0]);
// u grenq a = lists(Afini funci kod, size) vor stananq list a;
	start_sort(a, b, alg, size);
	
}
