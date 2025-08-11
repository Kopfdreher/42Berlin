/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:47:53 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/07/22 17:47:56 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdlib.h>

int	main(void)
{
	char	hello[] = "Hello";
	char	world[] = "World";
	int		n = INT_MIN;
	char	*nbr;

	ft_printf("%s %s! %i", hello, world, n);
	nbr = ft_itoa(n);
	write(1, nbr, ft_strlen(nbr));
}
