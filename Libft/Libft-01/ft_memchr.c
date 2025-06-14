/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:13:47 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/06/05 18:39:11 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   memchr - Memory Character Search                                         */

#include <string.h>
#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = (unsigned char *)s;
	while (i < n || *ptr != (unsigned char )c)
	{
		ptr++;
		i++;
	}
	if (*ptr == (unsigned char )c)
		return (ptr);
	else
		return (0);
}
/*
int	main()
{
	char	str[] = "Hello World!";
	char	c = 'l';
	char	*ptr;

	ptr = memchr(str, c, 4);
	ptr = ft_memchr(str, c, 4);
}
*/
