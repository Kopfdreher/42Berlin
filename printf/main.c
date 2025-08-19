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
//	printf("Hello World!");
	printf("**Original**\nINT:%i\nHEX:%x\nUINT:%u\n", -4444, -4444, -4444);
	ft_printf("**Cheap Version**\nINT:%i\nHEX:%x\nUINT:%u\n", -4444, -4444, -4444);
}
