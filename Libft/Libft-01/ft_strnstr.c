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

#include <string.h>

size_t	ft_strlen(char *str)
{
	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] && s2[i])
	{
		if (s[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i < n)
		return (s1[i] - s2[i]);
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	i = 0;
	little_len = ft_strlen(little);
	if (!little[0])
		return ((char *)big);
	if (little_len > len)
		return (0);

	while (i < len - little_len)
	{
		if (big[i] == little[0])
		{

			if (ft_strncmp(little, &big[i], little_len) == 0)
				return ((char *)&big[i]);
		i++;
	}
	return (0);
}

/*
int	main()
{
	char	big[] = "Needle in the haystack.";
	char	little[] = "in";
	char	*ptr;

	//ptr = strnstr(big, little, 14);
	ptr = ft_strnstr(big, little, 14);
}
*/
