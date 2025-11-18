/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 20:44:58 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/06/12 20:45:06 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* contiguously allocates space for count objects that are size bytes         */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;
	size_t			bytes;
	size_t			i;

	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	bytes = nmemb * size;
	i = 0;
	while (i < bytes)
	{
		ptr[i] = '\0';
		i++;
	}
	return (ptr);
}
