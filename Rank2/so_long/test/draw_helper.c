/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:30:46 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/14 16:16:56 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	draw_square(t_mlx *mlx, int x, int y, int size, int color)
{
	int	i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(mlx, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

void	draw_background(t_mlx *mlx, int color)
{
	int	i;
	int j;

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
}

void	draw_circle(t_mlx *mlx, int center_x, int center_y, int radius, int color)
{
	int	x;
	int	y;
	int	dist_sq;

	x = -radius;
	while (x <= radius)
	{
		y = -radius;
		while (y <= radius)
		{
			dist_sq = (x * x) + (y * y);
			if (dist_sq <= (radius *radius))
			{
				my_mlx_pixel_put(mlx, center_x + x, center_y + y, color);
			}
			y++;
		}
		x++;
	}
}
