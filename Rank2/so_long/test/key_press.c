/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:13:28 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/16 14:11:56 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_map *map)
{
	map->content[map->p_y][map->p_x] = '0';
	map->p_x--;
	map->content[map->p_y][map->p_x] = 'P';
}

static void key_is_left(t_map *map)
{

	ft_printf("LEFT\n");
	if (map->content[map->p_y][map->p_x - 1] == '0')
		move_left(map);
}

static void	key_is_up(t_map *map)
{
	ft_printf("UP\n");
	if (map->content[map->p_y - 1][map->p_x] == '0')
	{
		map->content[map->p_y][map->p_x] = '0';
		map->p_y--;
		map->content[map->p_y][map->p_x] = 'P';
	}
}

static void	key_is_right(t_map *map)
{
	ft_printf("RIGHT\n");
	if (map->content[map->p_y][map->p_x + 1] == '0')
	{
	map->content[map->p_y][map->p_x] = '0';
	map->p_x++;
	map->content[map->p_y][map->p_x] = 'P';
	}
}

static void	key_is_down(t_map *map)
{
	ft_printf("DOWN\n");
	if (map->content[map->p_y + 1][map->p_x] == '0')
	{
	map->content[map->p_y][map->p_x] = '0';
	map->p_y++;
	map->content[map->p_y][map->p_x] = 'P';
	}
}

int	handle_keypress(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
		free_exit(*mlx, 0);
	if (keycode == 97 || keycode == 65361)
		key_is_left(&mlx->map);
	if (keycode == 119 || keycode == 65362)
		key_is_up(&mlx->map);
	if (keycode == 100 || keycode == 65363)
		key_is_right(&mlx->map);
	if (keycode == 115 || keycode == 65364)
		key_is_down(&mlx->map);
	draw_map(mlx);
	return (0);
}
