/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 18:42:34 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/07/15 18:42:37 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while(str[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, char c)
{
	const char	*ptr;

	ptr = s;
	while (*ptr != c && *ptr)
		ptr++;
	if (*ptr == c)
		return ((char *)ptr);
	else
		return (0);
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	bytes;

	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	bytes = nmemb * size;
	while (bytes--)
		*ptr++ = 0;
	return (ptr);
}
