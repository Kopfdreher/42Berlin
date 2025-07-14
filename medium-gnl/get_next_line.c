/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:33:45 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/07/14 17:33:47 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		bytes_read;
	char	*buffer;

	buffer = ft_calloc(3 + 1, sizeof(char));
	if (!buffer)
		free(buffer);
	bytes_read = read(fd, buffer, 3);
	if (!bytes_read)
		return (NULL);
	return (buffer);

}

