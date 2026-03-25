/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:29:44 by lyov              #+#    #+#             */
/*   Updated: 2026/03/19 16:21:47 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lists(int *arr, int size)
{
	int		i;
	t_list	*new;
	t_list	*list;

	i = 0;
	list = NULL;
	while (i < size)
	{
		new = ft_lstnew(&arr[i]);
		if (!new)
		{
			ft_lstclear(&list, NULL);
			return (NULL);
		}
		ft_lstadd_front(&list, new);
		i++;
	}
	return (list);
}
