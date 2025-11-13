/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:06:15 by alehamad          #+#    #+#             */
/*   Updated: 2025/11/13 14:44:22 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_file(int fd, char *buffer)
{
	int		files;

	files = open(fd, O_RDWR);
	read(fd, buffer, sizeof(BUFFER_SIZE));
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];

	read_file(fd, buffer);


}
