/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 13:30:55 by lyov              #+#    #+#             */
/*   Updated: 2026/03/09 19:21:39 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*fill(char **argv)
{
	char	*arr;
	char	*temp;
	int		i;

	i = 1;
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
			i++;
		}
	}
	return (arr);
}

// int	main(int argc, char **argv)
// {
// 	printf("%s\n", fill(argv));
// }