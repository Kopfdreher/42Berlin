/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:26:15 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/16 16:04:58 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_exit(t_mlx mlx, int exitcode)
{
	if (mlx.img)
		mlx_destroy_image(mlx.mlx, mlx.img);
	if (mlx.wall)
		mlx_destroy_image(mlx.mlx, mlx.wall);
	if (mlx.player)
		mlx_destroy_image(mlx.mlx, mlx.player);
	if (mlx.coin)
		mlx_destroy_image(mlx.mlx, mlx.coin);
	if (mlx.door1)
		mlx_destroy_image(mlx.mlx, mlx.door1);
	if (mlx.door2)
		mlx_destroy_image(mlx.mlx, mlx.door2);
	if (mlx.map.content)
		free_strarr(mlx.map.content);
	if (mlx.win)
		mlx_destroy_window(mlx.mlx, mlx.win);
	if (mlx.mlx)
	{
		mlx_destroy_display(mlx.mlx);
		free(mlx.mlx);
	}
	exit(exitcode);
}

void	initialize(t_mlx *mlx)
{
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->img = NULL;
	mlx->addr = NULL;
	mlx->wall = NULL;
	mlx->coin = NULL;
	mlx->player = NULL;
	mlx->door1 = NULL;
	mlx->door2 = NULL;
}

void	init_map(t_map *map)
{
	map->content = NULL;
	map->width = 0;
	map->height = 0;
	map->p_count = 0;
	map->e_count = 0;
	map->c_count = 0;
	map->p_x = 0;
	map->p_y = 0;
	map->moves = 0;
	map->exit = 0;
}
