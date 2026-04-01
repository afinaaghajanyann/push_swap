/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:14:36 by larevsha          #+#    #+#             */
/*   Updated: 2026/04/01 17:57:22 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_strchr(const char *src, int c)
{
	int	i;

	i = 0;
	while (src[i] != (unsigned char)c && src[i] != '\0')
		i++;
	if (src[i] == (unsigned char)c)
	{
		return ((char *)&src[i]);
	}
	return (NULL);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*u1;
	unsigned char	*u2;

	u1 = (unsigned char *)s1;
	u2 = (unsigned char *)s2;
	i = 0;
	while (u1[i] || u2[i])
	{
		if (u1[i] != u2[i])
			return (u1[i] - u2[i]);
		i++;
	}
	return (0);
}

int	is_val_hertakanutyun(t_list **a, t_list **b)
{
	t_list	*temp;

	if (*b)
		return (0);
	temp = *b;
	temp = *a;
	while (temp && temp->next)
	{
		if (temp->num > (temp->next)->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}
