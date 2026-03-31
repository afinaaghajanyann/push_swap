/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larevsha <larevsha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 13:30:55 by lyov              #+#    #+#             */
/*   Updated: 2026/03/30 16:20:37 by larevsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_free(char *temp, t_vals *vals)
{
	free(temp);
	cleaning(vals);
}

char	*fill(char **argv, int i, t_vals *vals)
{
	char	*arr;
	char	*temp;

	arr = ft_strdup("");
	if (!arr)
		cleaning(vals);
	while (argv[i])
	{
		temp = arr;
		arr = ft_strjoin(arr, argv[i]);
		if (!arr)
			fill_free(temp, vals);
		free (temp);
		temp = arr;
		if (argv[i + 1])
		{
			arr = ft_strjoin(arr, " ");
			free (temp);
		}
		i++;
	}
	return (arr);
}
