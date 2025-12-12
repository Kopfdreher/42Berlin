/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:30:01 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/12 22:54:54 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <mlx.h>
# include "libft.h"
# include <sys/stat.h>

# ifndef MAX_MAP
#  define MAX_MAP 3
# endif

typedef struct	s_mlx {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		**map;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx;

// MLX_Helper
void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color);
int		handle_keypress(int keycode, t_mlx *mlx);
void	free_exit(t_mlx mlx);
void	initialize(t_mlx *mlx);

// Draw_Helper
void	draw_square(t_mlx *mlx, int x, int y, int size, int color);
void	draw_circle(t_mlx *mlx, int center_x,  int center_y, int radius, int color);
int		create_trgb(int t, int r, int g, int b);

// Map_Parsing
int		arg_is_valid(char *map_path);
char	**get_map_content(int map_fd);

#endif
