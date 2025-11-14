/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:06:15 by alehamad          #+#    #+#             */
/*   Updated: 2025/11/14 18:05:16 by alehamad         ###   ########.fr       */
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
	static char *stash = NULL;
	char buf[BUFFER_SIZE + 1];
	char *line;
	char *new_stash;
	ssize_t count_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return NULL;
	while ((count_read = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[count_read] = '\0';
		if (!stash)
			stash = malloc(1);
		stash = gnl_strjoin_free(stash, buf);
		if (gnl_strchr(stash, '\n'))
			break;
	}
	if (count_read < 0 || (count_read == 0 && !stash))
		return NULL;
	line = extract_line(stash);
	new_stash = gnl_strchr(stash, '\n');
	if (new_stash)
		new_stash++;
	else
		new_stash = NULL;
	free(stash);
	stash = new_stash;
	return line;
}

int	main()
{
	int fd = open("text", O_RDONLY);
	int i = 0;
	char * line = get_next_line(fd);
	while (line) {
		printf("%s       | ligne -> %d\n", line, i);
		//free(line);
		i++;
		line = get_next_line(fd);
	}

	close(fd);
	return (0);
}
