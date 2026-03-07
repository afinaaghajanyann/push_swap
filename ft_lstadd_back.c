/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatev <tatev@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 19:05:23 by afaghaja          #+#    #+#             */
/*   Updated: 2026/03/06 15:39:19 by tatev            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = new;
}

// #include <stdio.h>
// int main()
// {
// 	t_list *node1;
// 	int i;
// 	i = 4356;
// 	node1 = ft_lstnew(&i);

// 	int b = 5000;
// 	t_list *node2 = ft_lstnew(&b);

// 	ft_lstadd_back(&node1, node2);
// 	while (node1)
// 	{
// 		printf("%d \n", *(int *)node1 -> concctent);
// 		node1 = node1 -> next;
// 	}
// }