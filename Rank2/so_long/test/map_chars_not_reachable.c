/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chars_not_reachable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:36:24 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/16 17:00:48 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	flood_fill(char **map_cpy, int x, int y)
{
	if (map_cpy[y][x] == '1' || map_cpy[y][x] == 'F')
		return ;
	map_cpy[y][x] = 'F';
	flood_fill(map_cpy, x + 1, y);
	flood_fill(map_cpy, x - 1, y);
	flood_fill(map_cpy, x, y + 1);
	flood_fill(map_cpy, x, y - 1);
}

static int	chars_left(char **map_cpy, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->width)
	{
		j = 0;
		while (j < map->height)
		{
			if (map_cpy[j][i] == 'C' || map_cpy[j][i] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	chars_not_reachable(t_map *map)
{
	char	**map_cpy;
	int		i;

	map_cpy = ft_strarrcpy(map->content);
	if (!map_cpy)
		return (1);
	i = 0;
	flood_fill(map_cpy, map->p_x, map->p_y);
	if (chars_left(map_cpy, map))
	{
		return (ft_putstr_fd("Collectables or exit unreachable!\n", 2),
			free_strarr(map_cpy), 1);
	}
	i = 0;
	return (free_strarr(map_cpy), 0);
}
