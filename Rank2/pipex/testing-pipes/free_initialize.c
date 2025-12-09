/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_initialize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:06:55 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/09 19:49:45 by sgavrilo         ###   ########.fr       */
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

void	close_all(t_cmds *cmds)
{
		close(cmds->fd[1]);
		close(cmds->fd[0]);
		close(cmds->in_fd);
		close(cmds->out_fd);
}

t_cmds	*initialize(t_cmds *cmds, char **argv, char **envp)
{
	cmds = malloc(sizeof(t_cmds));
	if (!cmds)
		return (free_all(cmds), NULL);
	cmds->in_fd = open(argv[1], O_RDONLY);
	cmds->out_fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	cmds->envp = envp;
	cmds->value[0] = ft_split(argv[2], ' ');
	if (!cmds->value[0])
		return (free_all(cmds), NULL);
	cmds->value[1] = ft_split(argv[3], ' ');
	if (!cmds->value[1])
		return (free_all(cmds), NULL);
	if (pipe(cmds->fd) == -1)
		return (free_all(cmds), NULL);
	return (cmds);
}
