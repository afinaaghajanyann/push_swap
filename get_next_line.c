/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaghaja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:14:30 by larevsha          #+#    #+#             */
/*   Updated: 2026/04/01 19:15:02 by afaghaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	*first(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	if (!stash || !stash[i])
		return (NULL);
	while (stash[i] != '\n' && stash[i])
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_substr(stash, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

static char	*second(char *stash)
{
	int		i;
	char	*left;

	i = 0;
	while (stash[i] != '\n' && stash[i])
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	if (stash[i] == '\n')
		i++;
	left = ft_substr(stash + i, 0, ft_strlen(stash) - i);
	if (!left)
		return (NULL);
	free(stash);
	return (left);
}

static char	*add(int fd, char *stash)
{
	char	*buffer;
	char	*temp;
	int		count;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stash, '\n'))
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == 0)
			break ;
		if (count < 0)
		{
			free(stash);
			free(buffer);
			return (NULL);
		}
		buffer[count] = 0;
		temp = ft_strjoin(stash, buffer);
		free(stash);
		stash = temp;
	}
	free(buffer);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(stash);
		return (stash = NULL);
	}
	if (!stash)
		stash = ft_strdup("");
	stash = add(fd, stash);
	if (!stash || !stash)
		return (NULL);
	line = first(stash);
	temp = second(stash);
	stash = temp;
	if (!line || line[0] == '\0')
	{
		free(line);
		free(stash);
		stash = NULL;
		return (stash);
	}
	return (line);
}
