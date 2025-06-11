/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:12:24 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/06/03 19:13:56 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlcpy(char *dst, const char *src, unsigned int size)
{
	dst[--size] = 0;
	while (size--)
		dst[size] = src[size];
	return (dst);
}
/*
int	main(void)
{
	char src[] = "Hello again!";
	char dst[10];

	ft_strlcpy(dst, src, 5);
}
*/
