/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:26:46 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/16 17:00:28 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	if (argc == 2 && arg_is_valid(argv[1], &mlx.map))
	{
		initialize(&mlx);
		mlx.mlx = mlx_init();
		mlx.win = mlx_new_window(mlx.mlx, 64 * mlx.map.width, 64 
				* mlx.map.height, "so_long");
		mlx_key_hook(mlx.win, &handle_keypress, &mlx);
		if (load_sprites(&mlx) || draw_map(&mlx))
			return (1);
		mlx_hook(mlx.win, 17, 0, &close_window, &mlx);
		mlx_loop(mlx.mlx);
		free_exit(mlx, 0);
	}
}
