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

void	print_newline_helper(char *buffer)
{
	while (buffer && *buffer)
	{
		if (*buffer == '\n')
		{
			*buffer = '\\';
		}
		printf("%c", *buffer);
		buffer++;
	}
}

static char	*read_from_file(int fd)
{
	int			bytes_read;
	char		*buffer;
	static int	count;

	count = 1;
	printf("ft_calloc#[%d]---", count++);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		free(buffer);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	print_newline_helper(buffer);
	if (bytes_read <= 0)
		return (free(buffer), NULL);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char	*basin_buffer;

	basin_buffer = read_from_file(fd);
	return (basin_buffer);
}

