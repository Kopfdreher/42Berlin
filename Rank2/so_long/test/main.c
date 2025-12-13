/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:26:46 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/13 21:07:47 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	if (argc == 2 && arg_is_valid(argv[1], &mlx.map))
	{
		initialize(&mlx);
		ft_printf("Map-Width: %i\n", mlx.map.width);
		ft_printf("Map-Height: %i\n", mlx.map.height);
		mlx.mlx = mlx_init();
		mlx.win = mlx_new_window(mlx.mlx, 50 * mlx.map.width, 50 * 
						mlx.map.height, "Hello World!");
		mlx.img = mlx_new_image(mlx.mlx, 50 * mlx.map.width, 50 * mlx.map.height);
		mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_length,
							   &mlx.endian);
		my_mlx_pixel_put(&mlx, 5, 5, 0x00FF0000);
		//draw_square(&mlx, 10, 10, 100, 0x00FFFFFF);
		//draw_circle(&mlx, 100, 100, 100, 0x00FFFFFF);
		mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
		mlx_key_hook(mlx.win, &handle_keypress, &mlx);

		mlx_loop(mlx.mlx);
		free_exit(mlx);
	}
}

