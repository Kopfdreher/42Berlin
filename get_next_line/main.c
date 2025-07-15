/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:24:34 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/07/15 17:24:36 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	size_t	i;
	char	*line;

	line = "";
	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Opening the File\n");
		exit(1);
	}
	else
		printf("Opening successful\n");
	i = 0;
	while (line)
	{
		line = get_next_line(fd);
		printf("[%zu] - %s -\n", i++, line);
	}
}

