/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 16:48:11 by afaghaja          #+#    #+#             */
/*   Updated: 2026/03/07 16:48:12 by afaghaja         ###   ########.fr       */
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

void pars(int argc, char **argv, int *arr)
{
    int i;
    char **array;

    array = ft_split(argv[argc - 1], ' ');

    i = 0;
    while (array[i])
    {
       if (!isvalid(array[i]))
       {
            write(1, "ERROR", 5);
            return;
       }
       arr[i] = ft_atoi(array[i]);
       i++;
    }   
}
