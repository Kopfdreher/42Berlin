/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:21:33 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/07/15 17:21:34 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_get_line(char *stash);
static char		*ft_get_rest(char *stash);
static char		*read_ft(int fd, char *stash);
static size_t	ft_linelen(const char *str);

static char	*read_ft(int fd, char *stash)
{
	int		bytes_read;
	char	*buffer;

	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(stash), NULL);
		buffer[bytes_read] = '\0';
		stash = ft_strjoin_gnl(stash, buffer);
		if (!stash || ft_strchr_gnl(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (stash);
}

static char	*ft_get_line(char *stash)
{
	return (ft_strpardup_gnl(stash, ft_linelen(stash)));
}

static char	*ft_get_rest(char *stash)
{
	char	*rest;

	rest = ft_strpardup_gnl(&stash[ft_linelen(stash)],
			ft_strlen_gnl(stash) - ft_linelen(stash));
	return (free(stash), rest);
}

static size_t	ft_linelen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	if (str[len] == '\n')
		len++;
	return (len);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
	{
		if (stash[fd])
			free(stash[fd]);
		return (NULL);
	}
	if (!stash[fd])
		stash[fd] = ft_calloc_gnl(1, 1);
	if (!ft_strchr_gnl(stash[fd], '\n'))
	{
		stash[fd] = read_ft(fd, stash[fd]);
		if (!stash[fd])
			return (NULL);
	}
	line = ft_get_line(stash[fd]);
	stash[fd] = ft_get_rest(stash[fd]);
	if (!*line)
		return (free(line), free(stash[fd]), stash[fd] = NULL, NULL);
	return (line);
}
