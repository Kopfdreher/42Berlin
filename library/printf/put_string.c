/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:03:08 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/07/22 17:04:45 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_string(char *str)
{
	if (!str)
		return ((int)write(1, "(null)", 6));
	return ((int)write(1, str, ft_strlen(str)));
}
