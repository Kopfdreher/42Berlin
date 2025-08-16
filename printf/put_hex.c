/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:26:53 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/08/14 18:26:54 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_hexlen(unsigned long hex, char x)
{
	size_t	len;

	len = 0;
	while (hex)
	{
		hex /= 16;
		len++;
	}
	return (len);
}

static char	ft_hexconversion(unsigned long hex, char x)
{
	hex %= 16;
	if (hex < 10)
		return (hex + '0');
	else
	{
		if (x == 'x' || x == 'p')
			return (hex + 87);
		else
			return (hex + 55);
	}
}

static char	*ft_hextoa(unsigned long hex, char x)
{
	char	*nbr;
	size_t	len;

	len = ft_hexlen(hex, x);
	nbr = malloc(sizeof(char) * len + 1);
	if (!nbr)
		return (NULL);
	nbr[len] = '\0';
	while (hex)
	{
		nbr[--len] = ft_hexconversion(hex, x);
		hex /= 16;
	}
	return (nbr);
}

int	put_hex(unsigned long hex, char x)
{
	char	*nbr;
	int		output_len;

	output_len = 0;
	if (x == 'p')
	{
		if (!hex)
			return (write(1, "(nil)", 5), 5);
		write(1, "0x", 2);
		output_len += 2;
	}
	else
		hex = (unsigned int)hex;
	if (!hex)
		return (write(1, "0", 1), 1);
	nbr = ft_hextoa(hex, x);
	write(1, nbr, ft_hexlen(hex, x));
	output_len += ft_hexlen(hex, x);
	free(nbr);
	return (output_len);
}
