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

int	put_int(int n)
{
	char	*nbr;
	int		len;

	nbr = ft_itoa(n);
	len = ft_strlen(nbr);
	write(1, nbr, len);
	free(nbr);
	return (len);
}
