/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatev <tatev@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 15:09:40 by afaghaja          #+#    #+#             */
/*   Updated: 2026/03/07 16:40:24 by tatev            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	ptr = (char *)malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
