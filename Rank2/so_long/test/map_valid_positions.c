/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_positions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 17:38:25 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/16 18:00:09 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_player_position(t_map *map, int x, int y)
{
	map->p_count++;
	map->p_x = x;
	map->p_y = y;
}

static int	wrong_char_count(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->width)
	{
		j = 0;
		while (j < map->height)
		{
			if (map->content[j][i] == 'P')
				set_player_position(map, i, j);
			else if (map->content[j][i] == 'C')
				map->c_count++;
			else if (map->content[j][i] == 'E')
				map->e_count++;
			else if (map->content[j][i] != '1' && map->content[j][i] != '0')
				return (ft_putstr_fd("Error\nInvalid character!\n", 2), 1);
			j++;
		}
		i++;
	}
	if (map->p_count != 1 || map->e_count != 1 || map->c_count < 1)
		return (ft_putstr_fd("Error\nWrong character count!\n", 2), 1);
	return (0);
}

int	map_valid_positions(t_map *map)
{
	if (wrong_char_count(map) || chars_not_reachable(map))
		return (0);
	return (1);
}
