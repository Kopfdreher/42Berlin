/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:03:41 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/07/09 14:04:23 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_linelen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	return (len);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}



char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	join_len;
	size_t	i;
	char	*s_join;

	s1_len = ft_strlen(s1);
	if (s1_len > SIZE_MAX - ft_strlen(s2))
		return (NULL);
	join_len = s1_len + ft_strlen(s2);
	s_join = malloc(join_len * sizeof(char) + 1);
	if (!s_join)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		s_join[i] = s1[i];
		i++;
	}
	while (i < join_len)
	{
		s_join[i] = s2[i - s1_len];
		i++;
	}
	s_join[i] = '\0';
	return (s_join);
}

char	*ft_strpardup(const char *s, size_t end)
{
	char	*dup;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	if (len > end)
		len = end;
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
