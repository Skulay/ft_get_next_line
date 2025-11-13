/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:19:51 by alehamad          #+#    #+#             */
/*   Updated: 2025/11/13 16:48:48 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <fcntl.h>
#include <unistd.h>

char	*get_next_line(int fd);
char	*gnl_substr(const char *s, size_t start, size_t len);
char	*gnl_strjoin_free(char *buffer, const char *s2);
char	*gnl_strchr(const char *s, int c);
size_t	gnl_strlen(const char *s);

#endif
