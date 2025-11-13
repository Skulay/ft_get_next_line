/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alehamad <alehamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 14:06:44 by alehamad          #+#    #+#             */
/*   Updated: 2025/11/13 18:36:02 by alehamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*gnl_substr(const char *s, size_t start, size_t len)
// {
// 	char	*dst;
// 	size_t	s_len;

// 	if (!s)
// 		return (malloc(1));
// 	if (start >= len)
// 	{
// 		dst = malloc(1);
// 		if (!dst)
// 			return (0);
// 		dst[0] = '\0';
// 		return (dst);
// 	}
// 	if (len > s_len - start)
// 		len = s_len - start;
// 	dst = malloc(len + 1);
// 	if (!dst)
// 		return (0);
// 	ft_strlcpy(dst, s + start, len + 1);
// 	return (dst);
// }

char	*gnl_strjoin_free(char *s1, const char *s2)
{
	char	*dst;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	dst = malloc((gnl_strlen(s1) + gnl_strlen(s2) + 1) * sizeof(char));
	if (!dst)
		return (0);
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dst[i + j] = s2[j];
		j++;
	}
	free(s1);
	dst[i + j] = '\0';
	return (dst);
}

// char	*gnl_strchr(const char *s, int c)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == (char)c)
// 			return ((char *)&s[i]);
// 		i++;
// 	}
// 	if (s[i] == (char)c)
// 		return ((char *)&s[i]);
// 	return (0);
// }

size_t	gnl_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*gnl_strdup(const char *s)
{
	int		i;
	char	*dest;

	i = 0;
	while (s[i])
		i++;
	dest = malloc((i * sizeof(char)) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

