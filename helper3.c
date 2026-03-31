/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyov <lyov@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/29 20:49:55 by lyov              #+#    #+#             */
/*   Updated: 2026/03/29 21:58:57 by lyov             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexavorel(t_list **a)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		val;
	int		count;

	tmp1 = *a;
	while (tmp1)
	{
		tmp2 = *a;
		count = 0;
		val = tmp1->num;
		while (tmp2)
		{
			if (val > tmp2->num)
			{
				count++;
			}
			tmp2 = tmp2->next;
		}
		tmp1->index = count;
		tmp1 = tmp1->next;
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*ptr;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	ptr = malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*u1;
	unsigned char	*u2;

	u1 = (unsigned char *)s1;
	u2 = (unsigned char *)s2;
	i = 0;
	while (i < n && (u1[i] || u2[i]))
	{
		if (u1[i] != u2[i])
			return (u1[i] - u2[i]);
		i++;
	}
	return (0);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	putnbr(int total)
{
	char	c;

	if (total >= 10)
		putnbr(total / 10);
	c = (total % 10) + '0';
	write(2, &c, 1);
}
