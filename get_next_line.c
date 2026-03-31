/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larevsha <larevsha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:14:30 by larevsha          #+#    #+#             */
/*   Updated: 2026/03/30 20:08:51 by larevsha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static char	*first(char *stash)
{
	int		i;
	char	*line;

	i = 0;
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
	if (stash[i] == '\n')
		i++;
	left = ft_substr(stash + i, 0, ft_strlen(stash) - i);
	if (!left)
		return (NULL);
	return (left);
}

static char	*add(int fd, char *stash)
{
	char	*buffer;
	int		count;

	buffer = malloc (BUFFER_SIZE + 1);
	while (!ft_strchr(stash, '\n'))
	{
		count = read(fd, buffer, BUFFER_SIZE);
		if (count == 0)
			break ;
		if (count < 0)
		{
			free (stash);
			free (buffer);
			return (NULL);
		}
		buffer[count] = 0;
		stash = ft_strjoin(stash, buffer);
		if (!stash)
			break ;
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
		return (NULL);
	if (!stash)
		stash = ft_strdup("");
	if (!stash)
		return (NULL);
	stash = add(fd, stash);
	if (!stash)
		return (NULL);
	line = first(stash);
	temp = second(stash);
	free(stash);
	stash = temp;
	if (!line || line[0] == '\0')
	{
		free(line);
		free(stash);
		stash = NULL;
		return (NULL);
	}
	return (line);
}

//int	main(void)
//{
//	int		fd = open("test", O_RDONLY);
//	char	*a;
//	while ((a = get_next_line(fd)) != NULL)
//	{
//		printf("%s", a);
//		free (a);
//	}
//	close (fd);
//	return (0);
//}