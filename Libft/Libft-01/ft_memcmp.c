/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:58:51 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/06/05 18:40:31 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	i = 0;
	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	while (i < n - 1)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (ptr1[i] - ptr2[i]);
}
/*
int     main()
{
        char    s1[] = "";
        char    s2[] = "";
	int	difference;

	difference = 0;
	difference = memcmp(s1, s2, 3);
	printf("memcmp: %d", difference);
	difference = ft_memcmp(s1, s2, 3);
	printf("ft_memcmp: %d", difference);
}
*/
