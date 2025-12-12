/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 22:13:22 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/12 22:54:56 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**get_map_content(int map_fd)
{
	char	**map_content;
	int		i;
	int		map_too_big;

	i = 0;
	map_too_big = 0;
	map_content = malloc(sizeof(char *) * MAX_MAP + 1);
	if (!map_content)
		return (NULL);
	while (i < MAX_MAP)
	{
		map_content[i] = get_next_line(map_fd);
		if (i == (MAX_MAP - 1) && map_content[MAX_MAP - 1] != NULL)
			map_too_big = 1;
		i++;
	}
	map_content[i] = NULL;
	if (map_too_big)
		return (free_split(map_content), NULL);
	return (map_content);
}
