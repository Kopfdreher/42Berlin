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

#include "libft.h"

static size_t	print_ft_hexlen(unsigned long hex)
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

static char	print_ft_hexconversion(unsigned long hex, char x)
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

static char	*print_ft_hextoa(unsigned long hex, char x)
{
	char	*nbr;
	size_t	len;

	len = print_ft_hexlen(hex);
	nbr = malloc(sizeof(char) * len + 1);
	if (!nbr)
		return (NULL);
	nbr[len] = '\0';
	while (hex)
	{
		nbr[--len] = print_ft_hexconversion(hex, x);
		hex /= 16;
	}
	return (nbr);
}

int	print_put_hex(unsigned long hex, char x)
{
	char	*nbr;
	int		output_len;

	output_len = 0;
	if (x == 'p')
	{
		if (!hex)
			return ((int)write(1, "(nil)", 5));
		if (!(int)write(1, "0x", 2))
			return (-1);
		output_len += 2;
	}
	if (!hex)
		return ((int)write(1, "0", 1));
	nbr = print_ft_hextoa(hex, x);
	if (!(int)write(1, nbr, print_ft_hexlen(hex)))
		return (free(nbr), -1);
	output_len += print_ft_hexlen(hex);
	return (free(nbr), output_len);
}
