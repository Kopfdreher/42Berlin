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

int	main(void)
{
	char	hello[] = "Hello";
	char	world[] = "World";

	ft_printf("%s %s!", hello, world);
}
