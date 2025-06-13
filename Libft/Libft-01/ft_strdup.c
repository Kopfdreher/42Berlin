/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:57:09 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/06/13 19:57:11 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char 	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	len;
	size_t	i;
	
	i = 0;
	len = ft_strlen(s);
	dup = malloc(len + 1); // +1 for the \0
	if (!dup) // always check alloc
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0'; //end of the string
	return (dup);
}


