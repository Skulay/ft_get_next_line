/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:06:15 by alehamad          #+#    #+#             */
/*   Updated: 2025/11/14 21:30:16 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*extract_line(char *buf)
{
	char	*line;
	int		i;
	int		j;

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

char	*extract_rest(char *stash)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	if (!stash[i])
		return (free(stash), NULL);
	rest = malloc(gnl_strlen(stash + i) + 1);
	if (!rest)
		return (NULL);
	j = 0;
	while (stash[i])
		rest[j++] = stash[i++];
	rest[j] = '\0';
	free(stash);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*buf;
	char		*line;
	int			r;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	r = read(fd, buf, BUFFER_SIZE);
	while (!gnl_strchr(stash, '\n') && read(fd, buf, BUFFER_SIZE) > 0)
	{
		buf[r] = '\0';
		stash = gnl_strjoin_free(stash, buf);
		if (!stash)
			return (free(buf), NULL);
	}
	free(buf);
	if (!stash || !*stash)
		return (free(stash), stash = NULL, NULL);
	line = extract_line(stash);
	if (!line)
		return (NULL);
	stash = extract_rest(stash);
	return (line);
}

// int	main()
// {
// 	int fd = open("text", O_RDONLY);
// 	char * line = get_next_line(fd);
// 	while (line) {
// 		printf("%s", line);
// 		free(line);
// 		line = get_next_line(fd);
// 	}

// 	close(fd);
// 	return (0);
// }
