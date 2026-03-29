/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:48:11 by afaghaja          #+#    #+#             */
/*   Updated: 2026/03/29 19:46:17 by afaghaja         ###   ########.fr       */
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

int is_repetetive(char **str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_strcmp(str[i], str[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	*parsing(char *array, int *size)
{
	int		*arr;
	int		i;
	char	**splitted_arr;

	*size = 0;
	arr = malloc(sizeof(int) * (ft_strlen(array)));
	if (!arr)
	{
		free(array);
		cleaning();
	}
	
	splitted_arr = ft_split(array, ' ');
	while (splitted_arr[*size])
		(*size)++;
	i = 0;
	while (splitted_arr[i])
	{
		if (!isvalid(splitted_arr[i]) || !is_repetetive(splitted_arr))
			pars_free(array, arr, splitted_arr);
		arr[i] = ft_atoi(splitted_arr[i], array, arr, splitted_arr);
		i++;
	}
	free(splitted_arr);
	free(array);
	return (arr);
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