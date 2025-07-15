/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:56:23 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/07/06 14:56:24 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		*buffer;
	size_t			bytes_read;
	char			*line;
	char			*tmp;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (line);
	if (!buffer)
	{
		buffer = malloc(sizeof(char *) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE * sizeof(char));
		if (!bytes_read)
		{
			free(buffer);
			buffer = NULL;
			return (line);
		}
		buffer[bytes_read] = '\0';
	}
	while (1)
	{
		if (*buffer == '\n')
		{
			tmp = line;
			line = ft_strjoin(line, "\n");
			if (tmp)
				free(tmp);
			tmp = buffer;
			buffer = ft_strpardup(&buffer[1], 
					ft_strlen(&buffer[ft_linelen(buffer)]));
			free(tmp);
			break ;
		}
		if (*buffer && !line)
		{
			tmp = line;
			line = ft_strpardup(buffer, ft_linelen(buffer));
			free(tmp);
			tmp = buffer;
			buffer = ft_strpardup(&buffer[ft_linelen(buffer)], 
					ft_strlen(&buffer[ft_linelen(buffer)]));
			free(tmp);
		}
		if (*buffer && line)
		{
			tmp = line;
			line = ft_strjoin(line, ft_strpardup(buffer, ft_linelen(buffer)));
			free(tmp);
			tmp = buffer;
			buffer = ft_strpardup(&buffer[ft_linelen(buffer)], 
					ft_strlen(&buffer[ft_linelen(buffer)]));
			free(tmp);
		}
		if (!*buffer)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE * sizeof(char));
			buffer[bytes_read] = '\0';
			if (!*buffer)
			{
				if (buffer)
				{
					free(buffer);
					buffer = NULL;
				}
				break ;
			}
		}
	}
	return (line);
}
/*
int	main(void)
{
	int		fd; 
	char	*line;
	size_t	i;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
		printf("no file found\n");
	else
		printf("file opened\n");
	i = 0;
	while (i < 5)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
		i++;
	}
}
*/
