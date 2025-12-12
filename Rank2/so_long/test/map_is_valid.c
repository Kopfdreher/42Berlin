/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 20:36:50 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/12 22:50:49 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	path_is_valid(char *map_path)
{
	int	len;

	len = ft_strlen(map_path);
	if (len > 4)
	{
		if (ft_strnstr(&map_path[len - 4], ".ber", 4))
			return (1);
	}
	return (0);
}
/*
static int	map_no_rectangle(char **map_content)
{
}

static int	missing_walls(char **map_content)
{
}
*/
static int	map_is_valid(char *map_path)
{
	int		map_fd;
	char	**map_content;
	int		i;

	map_fd = open(map_path, O_RDONLY);
	if (map_fd == -1)
		return (perror(map_path), 0);
	map_content = get_map_content(map_fd);
	if (!map_content)
		return (0);
//	if (map_no_rectangle(map_content) || missing_walls(map_content))
//		return (0);
	i = 0;
	while (map_content[i])
	{
		ft_printf(map_content[i]);
		i++;
	}
	ft_printf("\n");
	free_split(map_content);
	close(map_fd);
	return (1);
}

int	arg_is_valid(char *map_path)
{
	return (path_is_valid(map_path) && map_is_valid(map_path));
}
