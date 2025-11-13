/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:06:15 by alehamad          #+#    #+#             */
/*   Updated: 2025/11/13 18:35:39 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
static char	*fill_stash(int fd)
{
	char	*stash;
	char	*tmp;
	size_t	i;

	stash = malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (read(fd, stash, BUFFER_SIZE))
	{
		i = 0;
		read(fd, stash, BUFFER_SIZE);
		while (stash[i] != '\n' && i < BUFFER_SIZE - 1)
			i++;
		if (stash[i] == '\n' && i < BUFFER_SIZE - 1)
		{
				tmp = gnl_strdup(stash);
				break;
		}
		else
			tmp = gnl_strjoin_free(stash, tmp);
	}
	return(tmp);
}

static char	*extract_line(char const *stash)
{
	size_t	i;
	char	*tmp;

	tmp = malloc((sizeof(char) * gnl_strlen(stash)) + 1);
	i = 0;
	while ((stash[i] != '\n' || stash[i] != '\0') && i < BUFFER_SIZE)
	{
		tmp[i] = stash[i];
		i++;
		if (stash[i] == '\n')
		{
			tmp[i] = '\n';
			i++;
			tmp[i] = '\0';
		}
	}
	return (tmp);
}


char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) == -1)
		return (NULL);
	*buffer = *fill_stash(fd);
	line = extract_line(buffer);
	return (line);
}

int	main()
{
	int fd = open("text", O_RDONLY);
	char * line = get_next_line(fd);
	while (line) {
		printf("%s\n", line);
		free(line);
		line = get_next_line(fd);
	}

	close(fd);
	return (0);
}
