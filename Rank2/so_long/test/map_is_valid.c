/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 20:36:50 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/16 10:49:12 by sgavrilo         ###   ########.fr       */
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
	return (ft_putstr_fd("Not a .ber-file!\n", 2), 0);
}

static int	map_no_rectangle(t_map *map)
{
	int		i;

	map->width = (int)get_line_len(map->content[0]);
	i = 1;
	while (map->content[i])
	{
		if (map->width != (int)get_line_len(map->content[i]))
			return (ft_putstr_fd("Map is not a rectangle!\n", 2), 1);
		i++;
	}
	map->height = i;
	return (0);
}

static int	missing_walls(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->width)
	{
		if (map->content[0][i] != '1')
			return (ft_putstr_fd("Missing upper wall!\n", 2), 1);
		if (map->content[map->height - 1][i] != '1')
			return (ft_putstr_fd("Missing lower wall!\n", 2), 1);
		if (i == 0 || i == map->width - '1')
		{
			j = 1;
			while (j < map->height)
			{
				if (map->content[j][i] != '1')
					return (ft_putstr_fd("Missing wall on the side!\n", 2), 1);
				j++;
			}
		}
		i++;
	}
	return (0);
}

static int	map_is_valid(char *map_path, t_map *map)
{
	int		map_fd;
	int		i;

	init_map(map);
	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
		return (perror(map_path), 0);
	map->content = get_map_content(map_fd);
	close(map_fd);
	if (!map->content)
		return (0);
	if (map_no_rectangle(map) || missing_walls(map)
		|| !map_valid_positions(map))
		return (free_strarr(map->content), 0);
	i = 0;
	while (map->content[i])
	{
		ft_printf(map->content[i]);
		i++;
	}
	ft_printf("\n");
	return (1);
}

int	arg_is_valid(char *map_path, t_map *map)
{
	return (path_is_valid(map_path) && map_is_valid(map_path, map));
}
