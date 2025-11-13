/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:06:15 by alehamad          #+#    #+#             */
/*   Updated: 2025/11/13 16:48:45 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_stash(int fd)
{
	char	*stash;
	char	*tmp;
	size_t	i;

	while ()
	{
		i = 0;
		read(fd, stash, BUFFER_SIZE);
		while ((stash[i] != '\n' || stash[i] != '\0') && i < BUFFER_SIZE - 1)
			i++;
		if ((stash[i] == '\n' || stash[i] == '\0') && i < BUFFER_SIZE - 1)
			break;
		else
			gnl_strjoin_free(stash, tmp);
	}
	return(tmp);
}

static char	*extract_line(char const *stash)
{
	size_t	i;


	i = 0;
	while (stash[i] != '\n' || stash[i] != '\0')
	{
		i++;
	}

}


char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 1) == -1)
		return (NULL);
	buffer[BUFFER_SIZE] = fill_stash(fd);
	extract_line(buffer);
}
