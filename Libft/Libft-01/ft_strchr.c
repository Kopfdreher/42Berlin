/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:22:50 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/06/03 19:11:38 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   strchr - String Character Search                                         */

#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, char c)
{
	const char	*ptr;

	ptr = s;
	while (*ptr != c && *ptr)
		ptr++;
	if (*ptr == c)
		return ((char *)ptr);
	else
		return (0);
}
/*
int	main()
{
	const char	s[] = "Hello World!";
	char		c = 'l';
	char		*test;
	
	test = ft_strchr(s, c);
	test = strchr(s, c);
	
}
*/
