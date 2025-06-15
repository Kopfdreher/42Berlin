/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:15:46 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/06/15 14:15:50 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while(s[len])
		len++;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	mem_len;

	if (start >= ft_strlen(s))
	{
		sub = malloc(sizeof(char));
		if (!sub)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	mem_len = ft_strlen(s) - start;
	if (mem_len > len)
		mem_len = len;
	sub = malloc(mem_len + 1);
	if (!sub)
		return (NULL);
	i = 0;
	while (i < mem_len && s[i + start])
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

size_t	ft_count(char const *s, char c)
{
	size_t	count_len;

	count_len = 1;	// 1 extra count for position 0
	while (*s)
	{
		if (*s == c)
			count_len++;
		s++;
	}
	return (count_len);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	start;
	size_t	count;
	char	**split;

	split = malloc((ft_count(s, c) + 1) * sizeof(char *));
	start = 0;
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			split[count] = ft_substr(s, start, i - start);
			if (!split[count])
				return (NULL);
			start = i + 1;
			count++;
		}
		i++;
	}
	split[count] = ft_substr(s, start, i);
	if (!split[count])
		return (NULL);
	return (split);
}

int	main()
{
	char	s[] = "Hello, how are you doing?";
	char	c = ' ';
	char	**split;

	split = ft_split(s, c);
	printf("%s\n, %s\n, %s\n, %s\n, %s\n", split[0], split[1], split[2], split[3], split[4]);
	free(split);
}
