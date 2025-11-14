/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:19:51 by alehamad          #+#    #+#             */
/*   Updated: 2025/11/14 21:25:25 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

char		*gnl_strdup(const char *s);
char		*gnl_strjoin_free(char *s1, char *s2);
char		*gnl_strchr(const char *s, int c);
char		*extract_line(char *buf);
char		*get_next_line(int fd);
size_t		gnl_strlen(char *s);

#endif
