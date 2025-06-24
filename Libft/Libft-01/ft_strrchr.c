/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:59:46 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/06/03 19:17:01 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   strrchr - String Character Search (points to the last accurance)         */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*chr;

	chr = NULL;
	while (1)
	{
		if (*s == (char)c)
			chr = s;
		if (!*s)
			break ;
		s++;
	}
	return ((char *)chr);
}
