/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:06:15 by alehamad          #+#    #+#             */
/*   Updated: 2025/11/14 19:30:10 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*extract_line(char *buf)
{
	char *line;
	int i;
	int j;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = buf[j];
		j++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		*line;
	char		*stash;
	int			bytes_read;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
		return (NULL);
	stash = malloc(1);
	stash[0] = '\0';
	stash = gnl_strjoin_free(stash, buffer);
	line = extract_line(stash);
	return (line);
}


int	main()
{
	int fd = open("text", O_RDONLY);
	char * line = get_next_line(fd);
	while (line) {
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}

	close(fd);
	return (0);
}

