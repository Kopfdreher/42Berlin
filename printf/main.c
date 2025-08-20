/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 19:10:37 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/08/18 19:10:38 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main()
{
	int	n = -4444;
	char	*p = NULL;
	printf("%i\n", ft_printf("%c%s%p%d%i%u%x%X%% %%%% %%  \n", '\0', p, "", n, n, n, n, n));
	ft_printf("%i\n", printf("%c%s%p%d%i%u%x%X%% %%%% %%  \n", '\0', p, "", n, n, n, n, n));
	printf("\n%i\n", ft_printf("%i%i%i%i%i", INT_MIN, INT_MAX, 0, -42, UINT_MAX));
	ft_printf("\n%i\n", printf("%i%i%i%i%i", INT_MIN, INT_MAX, 0, -42, UINT_MAX));
}
