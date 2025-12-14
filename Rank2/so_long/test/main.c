/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:26:46 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/14 16:29:21 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_mlx	mlx;
	int		img_width;
	int		img_height;

	if (argc == 2 && arg_is_valid(argv[1], &mlx.map))
	{
		initialize(&mlx);
		ft_printf("Map-Width: %i\n", mlx.map.width);
		ft_printf("Map-Height: %i\n", mlx.map.height);
		mlx.mlx = mlx_init();
		mlx.win = mlx_new_window(mlx.mlx, 64 * mlx.map.width, 64 * 
						mlx.map.height, "Hello World!");
		mlx.xpm = mlx_xpm_file_to_image(mlx.mlx, "./sprites/wall_01.xpm", &img_width, &img_height);
		if (!mlx.xpm)
		{
			ft_printf("Image not found or corrupted\n");
			free_exit(mlx, 1);
		}
		mlx.img = mlx_new_image(mlx.mlx, 64 * mlx.map.width, 64 * mlx.map.height);
		mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length,
							   &mlx.endian);
		draw_background(&mlx, 0x0072a276);
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.xpm, 0, 0);
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.xpm, 64, 0);
		mlx_key_hook(mlx.win, &handle_keypress, &mlx);

		mlx_loop(mlx.mlx);
		free_exit(mlx, 0);
	}
}

