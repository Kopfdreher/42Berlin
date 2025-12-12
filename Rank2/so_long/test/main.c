/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:26:46 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/12 21:40:26 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	if (argc == 2 && arg_is_valid(argv[1]))
	{
		initialize(&mlx);
		mlx.mlx = mlx_init();
		mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "Hello World!");
		mlx.img = mlx_new_image(mlx.mlx, 1920, 1080);
		mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length,
							   &mlx.endian);
		my_mlx_pixel_put(&mlx, 5, 5, 0x00FF0000);
		draw_square(&mlx, 10, 10, 100, 0x00FFFFFF);
		draw_circle(&mlx, 100, 100, 100, 0x00FFFFFF);
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
		mlx_key_hook(mlx.win, &handle_keypress, &mlx);

		mlx_loop(mlx.mlx);
		free_exit(mlx);
	}
}

