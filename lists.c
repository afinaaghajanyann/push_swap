/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larevsha <larevsha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:29:44 by lyov              #+#    #+#             */
/*   Updated: 2026/03/30 16:21:04 by larevsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lists(int *arr, int *size, t_vals *vals)
{
	int		i;
	t_list	*new;
	t_list	*list;

	i = 0;
	list = NULL;
	while (i < *size)
	{
		new = ft_lstnew(arr[i]);
		if (!new)
		{
			free(arr);
			ft_lstclear(&list, NULL);
			cleaning(vals);
		}
		ft_lstadd_back(&list, new);
		i++;
	}
	free(arr);
	return (list);
}
