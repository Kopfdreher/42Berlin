/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 13:47:36 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/06/14 13:47:41 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
/*
size_t	ft_isset(char	c, char const *set)
{
	size_t	set_index;
	size_t	is_set;
	
	set_index = ft_strlen(set);
	is_set = 0;
	while (set_index)
	{
		if (c == set[set_index])
			is_set = 1;
		set_index--;
	}
	return (is_set);
}
*/

char	*ft_strchr(const char *s, char c)
{
	const char	*ptr;

	ptr = s;
	while (*ptr != c && *ptr)
		ptr++;
	if (*ptr == c)
		return ((char *)ptr);
	else
		return (NULL);
}

char 	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	mem_len;

	if (!s)		// checks if Input is NULL
		return (NULL);	
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

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*n_s1;
	size_t	start;
	size_t	end;

	start = 0;
	end = ft_strlen(s1);
	while (ft_isset(s1[start], set))
		start++;
	while (ft_isset(s1[end], set))
		end--;
	n_s1 = ft_substr(s1, start, end - start);
	return (n_s1);
}

int	main()
{
	char	str[] = "  #\n Hello   World!  \n\n + - ";
	char	*trim;

	trim = ft_strtrim(str, " #\n+-");
	printf("%s\n", trim);
	free(trim);
}
