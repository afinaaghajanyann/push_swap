/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larevsha <larevsha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:12:30 by larevsha          #+#    #+#             */
/*   Updated: 2026/03/30 16:19:16 by larevsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cleaning(t_vals *vals)
{
	free(vals);
	write(2, "Error\n", 6);
	exit(1);
}

void	clean_splitted_arr(char **splitted_arr)
{
	int	i;

	i = 0;
	while (splitted_arr[i])
	{
		free(splitted_arr[i]);
		i++;
	}
	free(splitted_arr);
}

void	pars_free(char *array, int *arr, char **splitted_arr, t_vals *vals)
{
	free(arr);
	free(array);
	clean_splitted_arr(splitted_arr);
	cleaning(vals);
}

void	last_clean(t_list **a, t_list **b, t_vals *vals)
{
	ft_lstclear(a, NULL);
	ft_lstclear(b, NULL);
	free(vals);
}
