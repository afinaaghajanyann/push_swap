/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 16:33:09 by larevsha          #+#    #+#             */
/*   Updated: 2026/03/09 19:29:09 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_list	*ft_lstlast(t_list *lst)
// {
// 	t_list	*a;

// 	if (!lst)
// 		return (NULL);
// 	a = lst;
// 	while (a->next)
// 		a = a->next;
// 	return (a);
// }

// void	ft_lstadd_front(t_list **lst, t_list *new)
// {
// 	if (!lst || !new)
// 		return ;
// 	new->next = *lst;
// 	*lst = new;
// }

void	rra(t_list **a)
{
	t_list	*last;
	t_list	*prev;

	if (!a || !*a || !(*a)->next)
		return ;
	prev = *a;
	last = ft_lstlast(*a);
	while ((prev->next)->next != NULL)
		prev = prev->next;
	prev->next = NULL;
	last->next = *a;
	*a = last;
}

//int	main(void)
//{
//	t_list	*one = malloc(sizeof(t_list));
//	t_list	*two = malloc(sizeof(t_list));
//	t_list	*three = malloc(sizeof(t_list));
//	t_list	*temp1;
//	t_list	*temp2;
//	t_list	**head;

//	one->num = 5;
//	one->next = two;
//	two->num = 10;
//	two->next = three;
//	three->num = 15;
//	three->next = NULL;
//	head = &one;
//	temp1 = *head;
//	printf("minchev tpel\n");
//	while(temp1 != NULL)
//	{
//	}
//	ra(head);
//}