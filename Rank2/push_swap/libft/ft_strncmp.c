/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 18:34:21 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/06/05 19:59:57 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   strncmp - String Compare till n                                          */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	compare1;
	unsigned char	compare2;

	i = 0;
	while (i < n)
	{
		compare1 = (unsigned char)s1[i];
		compare2 = (unsigned char)s2[i];
		if (compare1 != compare2 || !compare1 || !compare2)
			return (compare1 - compare2);
		i++;
	}
	return (0);
}
/*
int	main()
{
	char	s1[] = "";
	char	s2[] = "";

	printf("ft_strncmp: %d\nstrncmp: %d.\n", 
	ft_strncmp(s1, s2, 11), strncmp(s1, s2, 11));
}
*/
