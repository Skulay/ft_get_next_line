/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 22:13:23 by alehamad          #+#    #+#             */
/*   Updated: 2025/11/19 23:57:09 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define MAX_FD 1024

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

char		*gnl_strdup(const char *s);
char		*gnl_strjoin_free(char *s1, char *s2);
char		*gnl_strchr(const char *s, int c);
char		*extract_line(char *buf);
char		*get_next_line(int fd);
size_t		gnl_strlen(char *s);

#endif
