/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 20:36:50 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/12 21:59:01 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	path_is_valid(char *map_path)
{
	int	len;

	len = ft_strlen(map_path);
	if (len > 4)
	{
		if (ft_strnstr(&map_path[len - 4], ".ber", 4))
			return (1);
	}
	return (0);
}

static int	map_is_valid(char *map_path)
{
	int	map_fd;

	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
		return (perror(map_path), 0);
	ft_printf(get_next_line(map_fd));
	close(map_fd);
	return (1);
}

int	arg_is_valid(char *map_path)
{
	return (path_is_valid(map_path) && map_is_valid(map_path));
}
