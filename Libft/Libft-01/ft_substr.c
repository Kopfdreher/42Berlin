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
/*   substr - Substring                                                       */

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

char 	*ft_substr(char const *s, unsigned int start, size_t len)
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
		return (sub);	// returns a pointer to an empty string 
	}
	mem_len = ft_strlen(s) - start;
	if (mem_len > len)
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

int	main()
{
	char	*str = malloc(11 * sizeof(char));
	int	i = -1;
	char	*sub;


	while (++i < 10)
		str[i] = i + 48;
	str[i] = '\0';
	sub = ft_substr(str, 4, 4);
	printf("%s", sub);
	free(str);
	free(sub);
}

