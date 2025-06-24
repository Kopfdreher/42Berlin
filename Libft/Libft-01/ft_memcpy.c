/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:44:15 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/06/03 19:06:48 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dptr;
	unsigned char	*sptr;

	dptr = (unsigned char *)dest;
	sptr = (unsigned char *)src;
	if (!n || dest == src)
		return (dest);
	while (n--)
		*dptr++ = *sptr++;
	return (dest);
}
/*
int	main(void)
{
	unsigned char src[] = "Hello Anthony";
	unsigned char dest[5];

	memcpy(dest, src, 3);
	ft_memcpy(dest, src, 5);
}
*/
