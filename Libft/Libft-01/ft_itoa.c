/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft_itoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:22:59 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/06/03 19:09:35 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_intlen(int nbr)
{
	size_t	len;

	if (nbr == 0)
		return (1);
	len = 0;
	if (nbr < 0)
		len++;
	while (nbr)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*nbr;
	size_t			intlen;
	size_t			i;
	unsigned int	number;

	intlen = ft_intlen(n);
	nbr = malloc(sizeof(char) * intlen + 1);
	if (!nbr)
		return (NULL);
	nbr[intlen] = '\0';
	i = intlen - 1;
	if (n < 0)
	{
		nbr[0] = '-';
		number = n * -1;
	}
	else
		number = n;
	if (n == 0)
		nbr[0] = '0';
	while (number)
	{
		nbr[i] = (number % 10) + 48;
		number = number / 10;
		i--;
	}
	return (nbr);
}
