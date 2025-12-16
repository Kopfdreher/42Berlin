/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:13:28 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/16 17:16:19 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	key_is_left(t_map *map)
{
	if (map->content[map->p_y][map->p_x - 1] == '0')
		move_left(map);
	else if (map->content[map->p_y][map->p_x - 1] == 'C')
	{
		move_left(map);
		map->c_count--;
	}
	else if (map->content[map->p_y][map->p_x - 1] == 'E' && !map->c_count)
	{
		move_left(map);
		map->exit++;
	}
}

static void	key_is_up(t_map *map)
{
	if (map->content[map->p_y - 1][map->p_x] == '0')
		move_up(map);
	else if (map->content[map->p_y - 1][map->p_x] == 'C')
	{
		move_up(map);
		map->c_count--;
	}
	else if (map->content[map->p_y - 1][map->p_x] == 'E' && !map->c_count)
	{
		move_up(map);
		map->exit++;
	}
}

static void	key_is_right(t_map *map)
{
	if (map->content[map->p_y][map->p_x + 1] == '0')
		move_right(map);
	else if (map->content[map->p_y][map->p_x + 1] == 'C')
	{
		move_right(map);
		map->c_count--;
	}
	else if (map->content[map->p_y][map->p_x + 1] == 'E' && !map->c_count)
	{
		move_right(map);
		map->exit++;
	}
}

static void	key_is_down(t_map *map)
{
	if (map->content[map->p_y + 1][map->p_x] == '0')
		move_down(map);
	else if (map->content[map->p_y + 1][map->p_x] == 'C')
	{
		move_down(map);
		map->c_count--;
	}
	else if (map->content[map->p_y + 1][map->p_x] == 'E' && !map->c_count)
	{
		move_down(map);
		map->exit++;
	}
}

int	handle_keypress(int keycode, t_mlx *mlx)
{
	if (keycode == 97 || keycode == 65361)
		key_is_left(&mlx->map);
	if (keycode == 119 || keycode == 65362)
		key_is_up(&mlx->map);
	if (keycode == 100 || keycode == 65363)
		key_is_right(&mlx->map);
	if (keycode == 115 || keycode == 65364)
		key_is_down(&mlx->map);
	if (keycode == 65307 || keycode == 17 || mlx->map.exit)
		free_exit(*mlx, 0);
	ft_printf("Moves: %i\n", mlx->map.moves);
	draw_map(mlx);
	return (0);
}
