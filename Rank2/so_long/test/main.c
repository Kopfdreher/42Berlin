/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:26:46 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/16 13:59:45 by sgavrilo         ###   ########.fr       */
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
		mlx.win = mlx_new_window(mlx.mlx, 64 * mlx.map.width, 64 * 
						mlx.map.height, "Hello World!");
		mlx_key_hook(mlx.win, &handle_keypress, &mlx);
		if (load_sprites(&mlx) || draw_map(&mlx))
			return (1);

		mlx_loop(mlx.mlx);
		free_exit(mlx, 0);
	}
}

