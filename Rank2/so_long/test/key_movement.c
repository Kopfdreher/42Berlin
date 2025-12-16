/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:08:39 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/16 15:13:11 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_map *map)
{
	map->content[map->p_y][map->p_x] = '0';
	map->p_x--;
	map->content[map->p_y][map->p_x] = 'P';
	map->moves++;
}

void	move_up(t_map *map)
{
	map->content[map->p_y][map->p_x] = '0';
	map->p_y--;
	map->content[map->p_y][map->p_x] = 'P';
	map->moves++;
}

void	move_right(t_map *map)
{
	map->content[map->p_y][map->p_x] = '0';
	map->p_x++;
	map->content[map->p_y][map->p_x] = 'P';
	map->moves++;
}

void	move_down(t_map *map)
{
	map->content[map->p_y][map->p_x] = '0';
	map->p_y++;
	map->content[map->p_y][map->p_x] = 'P';
	map->moves++;
}
