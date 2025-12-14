/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 17:30:46 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/14 17:38:17 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_background(t_mlx *mlx, int color)
{
	int	i;
	int j;

	mlx->img = mlx_new_image(mlx->mlx, 64 * mlx->map.width, 64 * mlx->map.height);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->line_length,
							   &mlx->endian);
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

void	draw_map(t_mlx *mlx)
{
	char	**map_cpy;
	int		i;

	map_cpy = ft_strarrcpy(mlx->map.content);
	i = 0;
	while (map_cpy[i])
		ft_printf(map_cpy[i++]);
}
