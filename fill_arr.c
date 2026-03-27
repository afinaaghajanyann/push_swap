/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 13:30:55 by lyov              #+#    #+#             */
/*   Updated: 2026/03/27 16:34:34 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*fill(char **argv, int i)
{
	char	*arr;
	char	*temp;

	arr = ft_strdup("");
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
