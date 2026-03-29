/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larevsha <larevsha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 13:30:55 by lyov              #+#    #+#             */
/*   Updated: 2026/03/28 20:35:54 by larevsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*fill(char **argv, int i)
{
	char	*arr;
	char	*temp;

	arr = ft_strdup("");
	if (!arr)
		cleaning();
	while (argv[i])
	{
		temp = arr;
		arr = ft_strjoin(arr, argv[i]);
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
