/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 20:35:52 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/06/13 20:35:54 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while(s[len])
		len++;
	return (len);
}

char 	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	mem_len;

	if (!s)		// checks if Input is NULL
		return (NULL);	
	if (start >= ft_strlen(s))
		return (""); <- Send an empty string back with calloc
	mem_len = ft_strlen(s) - start;
	if (mem_len < len)
		mem_len = len;
	sub = malloc(mem_len + 1);
	if (!sub)	// allocation succeded?
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
