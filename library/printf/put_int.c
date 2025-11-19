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

static size_t	print_ft_intlen(int nbr)
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

static char	*print_ft_itoa(int n)
{
	char			*str;
	size_t			len;
	unsigned int	nb;

	len = print_ft_intlen(n);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		nb = -n;
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
	return (str[len] = '\0', str);
}

int	print_put_int(int n)
{
	int		len;
	char	*nbr;

	nbr = print_ft_itoa(n);
	if (!nbr)
		return (0);
	len = write(1, nbr, print_ft_intlen(n));
	free(nbr);
	return (len);
}
