/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_initialize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:06:55 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/09 18:32:45 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

void	free_all(t_cmds *cmds)
{
	if (cmds)
	{
		if (cmds->value[0])
			free_split(cmds->value[0]);
		if (cmds->value[1])
			free_split(cmds->value[1]);
		free(cmds);
	}
}

int	initialize(t_cmds *cmds, char **argv, char **envp)
{
	cmds = malloc(sizeof(t_cmds));
	if (!cmds)
		return (free_all(cmds), 1);
	cmds->infile = argv[1];
	cmds->outfile = argv[4];
	cmds->envp = envp;
	cmds->value[0] = ft_split(argv[2], ' ');
	if (!cmds->value[0])
		return (free_all(cmds), 1);
	cmds->value[1] = ft_split(argv[3], ' ');
	if (!cmds->value[1])
		return (free_all(cmds), 1);
	if (pipe(cmds->fd) == -1)
		return (free_all(cmds), 1);
	return (0);
}
