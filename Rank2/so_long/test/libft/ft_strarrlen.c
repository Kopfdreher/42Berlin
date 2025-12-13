/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrlen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:27:21 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/13 20:11:12 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strarrlen(char **strarr)
{
	size_t	len;

	if (!strarr)
		return (0);
	len = 0;
	while (strarr[len])
		len++;
	return (len);
}
