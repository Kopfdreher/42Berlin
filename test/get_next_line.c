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

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <stdint.h>
#include <stdlib.h>

size_t	ft_linelen(const char* str)
{
	size_t	len;

	len = 0;
	while (str[len] && str[len] != '\n')
		len++;
	return (len);
}

size_t	ft_strlen(const char* str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	join_len;
	size_t	i;
	char	*s_join;

	s1_len = ft_strlen(s1);
	if (s1_len > SIZE_MAX - ft_strlen(s2))
		return (NULL);
	join_len = s1_len + ft_strlen(s2);
	s_join = malloc(join_len * sizeof(char) + 1);
	if (!s_join)
		return (NULL);
	i = 0;
	while (i < s1_len)
	{
		s_join[i] = s1[i];
		i++;
	}
	while (i < join_len)
	{
		s_join[i] = s2[i - s1_len];
		i++;
	}
	s_join[i] = '\0';
	return (s_join);
}

char	*ft_strpardup(const char *s, size_t end)
{
	char	*dup;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s);
	if (len > end)
		len = end;
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char*	get_next_line(int fd)
{
	static char*	buffer;
	size_t			bytes_read;
	char*			line;
	char*			tmp;

	line = NULL;
	if (!buffer)
	{
		buffer = malloc(sizeof(char*) * (10 + 1));
		if (!buffer)
			return (NULL);
		bytes_read = read(fd, buffer, 10);
		if (!bytes_read)
			return (line);
		buffer[bytes_read] = '\0';
	}
	while(1)
	{
		if (*buffer == '\n')
		{
			tmp = line;
			line = ft_strjoin(line, "\n");
			if (tmp)
				free(tmp);
			tmp = buffer;
			buffer = ft_strpardup(&buffer[1], ft_strlen(&buffer[ft_linelen(buffer)]));
			free(tmp);
			break;
		}
		if (*buffer && !line)
		{
			tmp = line;
			line = ft_strpardup(buffer, ft_linelen(buffer));
			free(tmp);
			tmp = buffer;
			buffer = ft_strpardup(&buffer[ft_linelen(buffer)], ft_strlen(&buffer[ft_linelen(buffer)]));
			free(tmp);
		}
		if (*buffer && line)
		{
			tmp = line;
			line = ft_strjoin(line, ft_strpardup(buffer, ft_linelen(buffer)));
			free(tmp);
			tmp = buffer;
			buffer = ft_strpardup(&buffer[ft_linelen(buffer)], ft_strlen(&buffer[ft_linelen(buffer)]));
			free(tmp);
		}
		if (!*buffer)
		{
			bytes_read = read(fd, buffer, 10);
			if (!*buffer)
				break;
		}
	}
	return (line);
}

int	main()
{ 
	int		fd; 
	char*	filename = "test.txt";
	char*	line;
	
	fd = open(filename, O_RDONLY);
	if	(fd == -1)
		printf("no file found\n");
	else
		printf("file opened\n");
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
}
