/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:44:32 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/13 16:47:57 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_line_len(const char *line)
{
	size_t	len;

	len = 0;
	while (line[len] && ft_isprint(line[len]))
		len++;
	return (len);
}
