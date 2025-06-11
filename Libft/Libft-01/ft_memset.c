/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:31:58 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/06/03 19:10:34 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	ft_printstring(int *str, int n);

void	*ft_memset(void *s, int c, unsigned int n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		*ptr++ = (unsigned char)c;
	}
	*ptr = 0;
	return (s);
}
/*
int	main(void)
{
	int str[9];
	int i = 0;
	
	while (i < 9)
		str[i++] = 5;
	ft_memset(str, 0, 9*sizeof(int));
	ft_printstring(str, 9);
	memset(str, 2, 4);
	ft_printstring(str, 9);
}

void	ft_printstring(int *str, int n)
{
	int	i;
	
	i = 0;
	while (i < n)
	{
		printf("%d,", str[i]);
		i++;
	}
	printf("\n");
}
*/
