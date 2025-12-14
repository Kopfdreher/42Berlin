/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:13:28 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/14 15:32:10 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	key_is_up(int keycode)
{
	return (keycode == 119 || keycode == 65362);
}

static int	key_is_right(int keycode)
{
	return (keycode == 100 || keycode == 65363);
}

static int	key_is_down(int keycode)
{
	return (keycode == 115 || keycode == 65364);
}

static int	key_is_left(int keycode)
{
	return (keycode == 97 || keycode == 65361);
}

int	handle_keypress(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		free_exit(*mlx, 0);
	}
	if (key_is_left(keycode))
		ft_printf("LEFT\n");
	if (key_is_up(keycode))
		ft_printf("UP\n");
	if (key_is_right(keycode))
		ft_printf("RIGHT\n");
	if (key_is_down(keycode))
		ft_printf("DOWN\n");
	return (0);
}
