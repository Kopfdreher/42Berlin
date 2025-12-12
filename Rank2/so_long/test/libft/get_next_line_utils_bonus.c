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

#include "libft.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (len);
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr_gnl(const char *s, char c)
{
	const char	*ptr;

	ptr = s;
	while (*ptr != c && *ptr && ptr)
		ptr++;
	if (*ptr == c)
		return ((char *)ptr);
	else
		return (0);
}

void	*ft_calloc_gnl(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			bytes;
	size_t			i;

	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	bytes = nmemb * size;
	i = 0;
	while (i < bytes)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}

char	*ft_strjoin_gnl(char *stash, char *buffer)
{
	size_t	stash_len;
	size_t	join_len;
	size_t	i;
	char	*join;

	stash_len = ft_strlen_gnl(stash);
	if (stash_len > SIZE_MAX - ft_strlen_gnl(buffer))
		return (NULL);
	join_len = stash_len + ft_strlen_gnl(buffer);
	join = ft_calloc_gnl(1, join_len * sizeof(char) + 1);
	i = 0;
	while (i < stash_len)
	{
		join[i] = stash[i];
		i++;
	}
	while (i < join_len)
	{
		join[i] = buffer[i - stash_len];
		i++;
	}
	return (free(stash), join);
}

char	*ft_strpardup_gnl(char *s, size_t end)
{
	char	*dup;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen_gnl(s);
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
