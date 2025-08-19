/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:05:36 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/07/22 17:05:37 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_intlen(int nbr)
{
	size_t	len;

	len = 0;
	if (nbr <= 0)
		len++;
	while (nbr)
	{
		nbr = nbr / 10;
		len++;
	}
	return (len);
}

static char	*ft_itoa(int n)
{
	char			str[ft_intlen(n) + 1];
	size_t			len;
	unsigned int	nb;

	len = ft_intlen(n);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		nb = n * -1;
	}
	else
		nb = n;
	if (n == 0)
		str[0] = '0';
	while (nb)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

int	put_int(int n)
{
	return ((int)write(1, ft_itoa(n), ft_strlen(nbr)));
}
