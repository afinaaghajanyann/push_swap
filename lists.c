/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larevsha <larevsha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:29:44 by lyov              #+#    #+#             */
/*   Updated: 2026/03/25 20:15:45 by larevsha         ###   ########.fr       */
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
	free(arr);
	return (list);
}
