/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:30:46 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/16 17:05:02 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_background(t_mlx *mlx, int color)
{
	int	i;
	int	j;

	if (!mlx->img)
	{
		mlx->img = mlx_new_image(mlx->mlx, 64 * mlx->map.width,
				64 * mlx->map.height);
		mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
				&mlx->line_length, &mlx->endian);
	}
	i = 0;
	while (i < mlx->map.height * 64)
	{
		j = 0;
		while (j < mlx->map.width * 64)
		{
			my_mlx_pixel_put(mlx, j, i, color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

int	load_sprites(t_mlx *mlx)
{
	int		width;
	int		height;

	mlx->wall = mlx_xpm_file_to_image(mlx->mlx,
			"./sprites/wall_01.xpm", &width, &height);
	mlx->player = mlx_xpm_file_to_image(mlx->mlx,
			"./sprites/player_01.xpm", &width, &height);
	mlx->coin = mlx_xpm_file_to_image(mlx->mlx,
			"./sprites/coin_01.xpm", &width, &height);
	mlx->door1 = mlx_xpm_file_to_image(mlx->mlx,
			"./sprites/door_01.xpm", &width, &height);
	mlx->door2 = mlx_xpm_file_to_image(mlx->mlx,
			"./sprites/door_02.xpm", &width, &height);
	if (!mlx->wall || !mlx->player || !mlx->coin || !mlx->door1 || !mlx->door2)
	{
		ft_printf("Image not found or corrupted\n");
		free_exit(*mlx, 1);
		return (1);
	}
	return (0);
}

static void	put_sprite(t_mlx *mlx, void *sprite, int i, int j)
{
	mlx_put_image_to_window(mlx->mlx, mlx->win, sprite, i * 64, j * 64);
}

int	draw_map(t_mlx *mlx)
{
	int		i;
	int		j;

	draw_background(mlx, 0x0072a276);
	i = 0;
	while (i < mlx->map.width)
	{
		j = 0;
		while (j < mlx->map.height)
		{
			if (mlx->map.content[j][i] == '1')
				put_sprite(mlx, mlx->wall, i, j);
			if (mlx->map.content[j][i] == 'P')
				put_sprite(mlx, mlx->player, i, j);
			if (mlx->map.content[j][i] == 'E' && mlx->map.c_count)
				put_sprite(mlx, mlx->door1, i, j);
			if (mlx->map.content[j][i] == 'E' && !mlx->map.c_count)
				put_sprite(mlx, mlx->door2, i, j);
			if (mlx->map.content[j][i] == 'C')
				put_sprite(mlx, mlx->coin, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
