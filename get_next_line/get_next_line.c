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

#include "get_next_line.h"


static char	*ft_get_line(char *stash);
static char	*ft_get_rest(char *stash);
static char	*read_ft(int fd, char *stash);
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
		stash = ft_strjoin(stash, buffer);
		if (!stash || ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (stash);
}

static char	*ft_get_line(char *stash)
{
	return (ft_strpardup(stash, ft_linelen(stash)));
}

static char	*ft_get_rest(char *stash)
{
	char	*rest;

	rest = ft_strpardup(&stash[ft_linelen(stash)],
			ft_strlen(stash) - ft_linelen(stash));
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
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (stash)
			free(stash);
		return (NULL);
	}
	if (!stash)
		stash = ft_calloc(1, 1);
	if (!ft_strchr(stash, '\n'))
	{
		stash = read_ft(fd, stash);
		if (!stash)
			return (NULL);
	}
	line = ft_get_line(stash);
	stash = ft_get_rest(stash);
	if (!*line)
		return (free(line), free(stash), stash = NULL, NULL);
	return (line);
}
