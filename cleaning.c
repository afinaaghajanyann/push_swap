/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larevsha <larevsha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 17:12:30 by larevsha          #+#    #+#             */
/*   Updated: 2026/03/28 18:06:52 by larevsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cleaning(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	pars_free(char *array, int *arr, char **splitted_arr)
{
	free(arr);
	free(array);
	free(splitted_arr);
	cleaning();
}