/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_func.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 17:42:04 by afaghaja          #+#    #+#             */
/*   Updated: 2026/03/05 18:15:32 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_func(t_list **a)
{
	t_list	*first;
	t_list	*last;

	if (!a || !(*a) || !(*a)->next)
		return ;
	first = *a;
	last = ft_lstlast(first);
	*a = first->next;
	last->next = first;
	first->next = NULL;
}

// int	main(void)
// {
// 	t_list *node1 = ft_lstnew(5);
// 	t_list *node2 = ft_lstnew(6);
// 	t_list *node3 = ft_lstnew(7);
// 	t_list *node4 = ft_lstnew(8);

// 	node1->next = node2;
// 	node2->next = node3;
// 	node3->next = node4;

// 	r_func(&node1);

// 	while (node1)
// 	{
// 		printf("%d\n", node1->value);
// 		node1 = node1->next;
// 	}
// 	return (0);
// }