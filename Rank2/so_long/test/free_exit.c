/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:26:15 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/12 19:55:47 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_exit(t_mlx mlx)
{
	mlx_destroy_image(mlx.mlx, mlx.img);
	mlx_destroy_display(mlx.mlx);
	free(mlx.mlx);
	exit(0);
}

void	initialize(t_mlx *mlx)
{
	mlx->mlx = NULL;
	mlx->win = NULL;
	mlx->img = NULL;
	mlx->addr = NULL;
}
