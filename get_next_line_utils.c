/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:14:36 by larevsha          #+#    #+#             */
/*   Updated: 2026/03/31 21:13:17 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// size_t	ft_strlen(const char *s)
// {
// 	const char	*p;

// 	p = s;
// 	while (*p)
// 		p++;
// 	return (p - s);
// }

// char	*ft_strjoin(char *str1, char *str2)
// {
// 	size_t	i;
// 	size_t	j;
// 	char	*newstr;

// 	i = 0;
// 	j = 0;
// 	newstr = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
// 	if (!newstr)
// 		return (NULL);
// 	while (str1[i])
// 	{
// 		newstr[i] = str1[i];
// 		i++;
// 	}
// 	while (str2[j])
// 	{
// 		newstr[i + j] = str2[j];
// 		j++;
// 	}
// 	newstr[i + j] = '\0';
// 	free(str1);
// 	return (newstr);
// }

// char	*ft_strdup(char *s)
// {
// 	size_t	i;
// 	char	*a;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	a = malloc(i + 1);
// 	i = 0;
// 	if (a == 0)
// 		return (NULL);
// 	while (s[i] != '\0')
// 	{
// 		a[i] = s[i];
// 		i++;
// 	}
// 	a[i] = '\0';
// 	return (a);
// }

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
	temp = *a;
	while (temp && temp->next)
	{
		if (temp->num < (temp->next)->num)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t		i;
// 	char		*a;

// 	i = 0;
// 	if (!s)
// 		return (NULL);
// 	if (start >= ft_strlen(s))
// 		return (ft_strdup(""));
// 	if (len > ft_strlen(s + start))
// 		len = ft_strlen(s + start);
// 	a = malloc(len + 1);
// 	if (!a)
// 		return (NULL);
// 	while (i < len)
// 	{
// 		a[i] = s[start + i];
// 		i++;
// 	}
// 	a[i] = '\0';
// 	return (a);
// }
