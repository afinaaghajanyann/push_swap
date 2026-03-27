/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 00:52:44 by lyov              #+#    #+#             */
/*   Updated: 2026/03/27 15:47:05 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	valueing(t_bench *count, t_oper *opers)
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
		if (!(count->simple + count->medium + count->complex + count->adaptive
				+ count->bench))
			return (0);
	}
	if (count->simple + count->medium + count->complex + count->adaptive == 2
		|| count->bench == 2)
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

int	start_point(int pars, t_list **a, t_list **b)
{
	int	i;

	i = 0;
	if (pars == -1)
	{
		free(a);
		free(b);
		write(2, "Error\n", 6);
		exit(1);
	}
	else if (pars == 0)
		i = 1;
	else if (pars == 1)
		i = 2;
	else if (pars == 2)
		i = 3;
	return (i);
}

void	start_sort(t_list **a, t_list **b, int alg, float dis)
{
	if (alg == 1 || alg == 11)
		basic(a, b);
	else if (alg == 2 || alg == 12)
		chunk(a, b);
	else if (alg == 3 || alg == 13)
		radix(a, b);
	else if (alg == 4 || alg == 14 || alg == 0 || alg == 10)
		custom(dis, a, b);
}

void	putnbr(int total)
{
	char	c;

	if (total >= 10)
		putnbr(total / 10);
	c = (total % 10) + '0';
	write(2, &c, 1);
}

void	write_t_oper(t_oper *opers)
{
	write(2, "sa: ", 4);
	putnbr(opers->sa);
	write(2, " ", 1);
	write(2, "sb: ", 4);
	putnbr(opers->sb);
	write(2, " ", 1);
	write(2, "ss: ", 4);
	putnbr(opers->ss);
	write(2, " ", 1);
	write(2, "pa: ", 4);
	putnbr(opers->sb);
	write(2, " ", 1);
}

void	isbench(int alg, t_oper *opers, int number)
{
	int		total;
	char	*s1;
	char	*s2;

	if (alg < 10)
		return ;
	total = opers->pa + opers->pb + opers->ra + opers->rb + opers->rra
		+ opers->rrb + opers->rrr + opers->sa;
	write(2, "disorder: ", 11);
	s1 = ft_itoa(number);
	s2 = ft_itoa(return_rem(number));
	write(2, s1, ft_strlen(s1));
	write(2, ".", 1);
	write(2, s2, ft_strlen(s2));
	write(2, "\n", 1);
	free(s1);
	free(s2);
	write(2, "strategy: ", 11);
	if (number == 1)
		write(2, "Simple / O(n^2)\n", 16);
	else if (number == 2)
		write(2, "Adaptive / O(n√n)\n", 18);
	else if (number == 3)
		write(2, "Complex / O(nlogn)\n", 19);
	write(2, "total_ops: ", 12);
	putnbr(total);
	write(2, "\n", 1);
}

int	main(int argc, char **argv)
{
	t_list	**a;
	t_list	**b;
	t_bench	count;
	t_oper	opers;
	int		alg;
	int		pars;
	int		i;
	int		size;

	a = NULL;
	b = NULL;
	*a = malloc(sizeof(t_list));
	*b = malloc(sizeof(t_list));
	valueing(&count, &opers);
	pars = bench_pars(argv, &count);
	i = start_point(pars, a, b);
	alg = method(&count);
	size = argc - i;
	*a = lists(parsing(fill(argv, i), argc), size);
	start_sort(a, b, alg, disorder(a));
	isbench(alg, &opers, custom(disorder(a), a, b));
	free(a);
	free(b);
}
