/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unsigned_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:05:48 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/07/22 17:05:49 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	print_ft_ulen(unsigned int u)
{
	size_t	len;

	len = 0;
	while (u)
	{
		u /= 10; 
		len++;
	}
	return (len);
}

static char	*print_ft_utoa(unsigned int u)
{
	size_t	len;
	char	*nbr;

	len = print_ft_ulen(u);
	nbr = malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (NULL);
	nbr[len] = '\0';
	while (u)
	{
		nbr[--len] = (u % 10) + '0';
		u /= 10;
	}
	return (nbr);
}

int	print_put_unsigned_int(unsigned int u)
{
	char	*nbr;
	int		output_len;

	if (u == 0)
		return (write(1, "0", 1));
	nbr = print_ft_utoa(u);
	output_len = (int)write(1, nbr, print_ft_strlen(nbr));
	free(nbr);
	return (output_len);
}
