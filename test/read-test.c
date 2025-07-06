/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read-test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:56:23 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/07/06 14:56:24 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int	main()
{
	int	fd;
	char* filename = "test.txt";
	char	buffer[10];
	size_t	bytes_read;
	char*	ptr;

	fd = open(filename, O_RDWR);
	if	(fd == -1)
		printf("no file found\n");
	else 
		printf("file opened\n");
	printf("%s", get_next_line(fd));
}

char*	get_next_line(int fd)
{
	char	buffer[10];
	size_t	bytes_read;
	char*	ptr;
	char*	rtrn;

	while(1)
	{
		ptr = buffer;
		while (*ptr != '\n' && *ptr)
		{
			write(1, ptr, 1);
			ptr++;
		}
		if (*ptr == '\n')
			break;
	}
}
