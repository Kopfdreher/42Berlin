/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:30:01 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/14 17:35:21 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include "libft.h"
# include <sys/stat.h>

typedef struct	s_map {
	char	**content;
	int		width;
	int		height;
	int		p_count;
	int		e_count;
	int		c_count;
	int		p_x;
	int		p_y;
}	t_map;

typedef struct	s_mlx {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	t_map	map;
	void	*xpm;
}	t_mlx;

// MLX_Helper
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int		handle_keypress(int keycode, t_mlx *mlx);
void	free_exit(t_mlx mlx, int exitcode);
void	initialize(t_mlx *mlx);

// Draw_Helper
void	draw_background(t_mlx *mlx, int color);
void	draw_map(t_mlx *mlx);

// Map_Parsing
int		arg_is_valid(char *map_path, t_map *map);
char	**get_map_content(int map_fd);
void	init_map(t_map *map);
int		map_valid_positions(t_map *map);
int		chars_not_reachable(t_map *map);

#endif
