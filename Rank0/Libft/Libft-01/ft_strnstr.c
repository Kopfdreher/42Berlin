/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 19:30:54 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/06/06 21:07:27 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (!needle_len)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i + needle_len <= len)
	{
		if (!ft_strncmp(&haystack[i], needle, needle_len))
			return ((char *)&haystack[i]);
		i++;
	}
	return (NULL);
}
/*
int	main()
ft_strnstr(((void*)0), "fake", 3);
*/
