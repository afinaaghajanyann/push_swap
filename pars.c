/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:48:11 by afaghaja          #+#    #+#             */
/*   Updated: 2026/03/31 15:38:44 by afaghaja         ###   ########.fr       */
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

int	is_repetetive(char **str, char *array, int *arr, char **splitted_arr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_atoi(str[i], array, arr, splitted_arr)
				== ft_atoi(str[j], array, arr, splitted_arr))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ankap(int *size, char **splitted_arr, t_vals *vals, char *array)
{
	int			i;
	long long	val;

	i = 0;
	while (i < *size)
	{
		val = ft_atoi(splitted_arr[i], NULL, NULL, NULL);
		if (val < -2147483648LL || val > 2147483647LL)
			pars_free(array, NULL, splitted_arr, vals);
		i++;
	}
}

int	*parsing(char *array, int *size, t_vals *vals)
{
	int		*arr;
	int		i;
	char	**splitted_arr;

	splitted_arr = ft_split(array, ' ');
	if (!splitted_arr)
		pars_free(array, NULL, NULL, vals);
	*size = 0;
	while (splitted_arr[*size])
		(*size)++;
	ankap(size, splitted_arr, vals, array);
	arr = malloc(sizeof(int) * (*size));
	if (!arr)
		pars_free(array, NULL, splitted_arr, vals);
	i = -1;
	while (splitted_arr[++i])
	{
		if (!isvalid(splitted_arr[i])
			|| !is_repetetive(splitted_arr, array, arr, splitted_arr))
			pars_free(array, arr, splitted_arr, vals);
		arr[i] = (int)ft_atoi(splitted_arr[i], NULL, NULL, NULL);
	}
	free(array);
	return (clean_splitted_arr(splitted_arr), arr);
}
