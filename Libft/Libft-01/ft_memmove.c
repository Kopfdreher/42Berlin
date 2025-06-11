/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:22:59 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/06/03 19:09:35 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*cpy;

	i = 0;
	while (i < n)
	{
		cpy[i] = ((unsigned char *)src)[i];
		((unsigned char *)dest)[i] = cpy[i];
		i++;
	}
	return ((void *)dest);
}
/*
int	main(void)
{
	char dest[] = "0000000";
	char src[] = "Hello";
	
	ft_memmove(dest, src, 3);
	memmove(dest, src, 5);
}
*/
