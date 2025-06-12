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

#include <limits.h>

void *calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	if (nmemb * size < INT_MAX)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
//check for SIZE_MAX and the hints on the exercise pdfs
