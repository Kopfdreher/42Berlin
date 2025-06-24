/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 09:51:31 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/06/14 09:51:34 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
