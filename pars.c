/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:48:11 by afaghaja          #+#    #+#             */
/*   Updated: 2026/03/19 16:21:15 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	isvalid(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	pars(int argc, char **argv, int *arr)
{
	int		i;
	char	**array;

	array = ft_split(argv[argc - 1], ' ');
	i = 0;
	while (array[i])
	{
		if (!isvalid(array[i]))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		arr[i] = ft_atoi(array[i]);
		i++;
	}
}

// #include "push_swap.h"
// #include <stdio.h>

// int	count_words(char *str)
// {
// 	int	i;
// 	int	count;

// 	i = 0;
// 	count = 0;
// 	while (str[i])
// 	{
// 		while (str[i] == ' ')
// 			i++;
// 		if (str[i])
// 			count++;
// 		while (str[i] && str[i] != ' ')
// 			i++;
// 	}
// 	return (count);
// }

// int	main(int argc, char **argv)
// {
// 	int arr[100];
// 	int size;
// 	int i;

// 	if (argc < 2)
// 		return (0);

// 	pars(argc, argv, arr);

// 	size = count_words(argv[argc - 1]);

// 	i = 0;
// 	while (i < size)
// 	{
// 		printf("%d\n", arr[i]);
// 		i++;
// 	}
// }