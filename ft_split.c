/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatev <tatev@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 17:03:07 by afaghaja          #+#    #+#             */
/*   Updated: 2026/03/06 15:39:01 by tatev            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	int		in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (!in_word && *s != c)
		{
			in_word = 1;
			count++;
		}
		if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static void	free_split(char **ptr, size_t j)
{
	while (j > 0)
	{
		free(ptr[j - 1]);
		j--;
	}
	free(ptr);
}

static int	fill_split(char **ptr, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len = 0;
			while (s[i + len] && s[i + len] != c)
				len++;
			ptr[j] = ft_substr(s, i, len);
			if (!ptr[j])
				return (free_split(ptr, j), 0);
			j++;
			i += len;
		}
		else
			i++;
	}
	ptr[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;

	if (!s)
		return (NULL);
	ptr = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!ptr)
		return (NULL);
	if (!fill_split(ptr, s, c))
		return (NULL);
	return (ptr);
}
