/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 14:58:13 by larevsha          #+#    #+#             */
/*   Updated: 2026/03/09 19:27:53 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	ft_lstadd_front(t_list **lst, t_list *new)
// {
// 	if (!lst || !new)
// 		return ;
// 	new->next = *lst;
// 	*lst = new;
// }

void	pa(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!a || !b || !*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = NULL;
	ft_lstadd_front(a, temp);
}

//int	main(void)
//{
//	t_list	*one = malloc(sizeof(t_list));
//	t_list	*two = malloc(sizeof(t_list));
//	t_list	*help;
//	t_list	**a;
//	t_list	**b;
//	a = &one;
//	b = &two;
//	two->num = 5;
//	two->next = NULL;
//	one->num = 10;
//	one->next = NULL;
//	pa(a, b);
//	help = one;
//	while(help != NULL)
//	{
//		printf("%d\n", help->num);
//		help = help->next;
//	}
//}