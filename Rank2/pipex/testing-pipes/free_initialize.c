/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_initialize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 15:06:55 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/10 17:13:37 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "pipex.h"

void	file_err(char *file, int *error)
{
	*error = 1;
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(file, 2);
	ft_putstr_fd(": ", 2);
	perror("");
}

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
	if (cmds->fd[1] != -1)
		close(cmds->fd[1]);
	if (cmds->fd[0] != -1)
		close(cmds->fd[0]);
	if (cmds->in_fd != -1)
		close(cmds->in_fd);
	if (cmds->out_fd != -1)
		close(cmds->out_fd);
}

t_cmds	*initialize(t_cmds *cmds, char **argv, char **envp)
{
	cmds = malloc(sizeof(t_cmds));
	if (!cmds)
		return (free_all(cmds), NULL);
	cmds->error = 0;
	cmds->id[0] = -1;
	cmds->id[1] = -1;
	cmds->in_fd = -1;
	cmds->infile = argv[1];
	cmds->outfile = argv[4];
	cmds->envp = envp;
	cmds->value[0] = ft_split(argv[2], ' ');
	cmds->out_fd = open(cmds->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (cmds->out_fd == -1)
		return (file_err(cmds->outfile, &cmds->error), free_all(cmds), NULL);
	if (!cmds->value[0])
		return (free_all(cmds), NULL);
	cmds->value[1] = ft_split(argv[3], ' ');
	if (!cmds->value[1])
		return (free_all(cmds), NULL);
	if (pipe(cmds->fd) == -1)
		return (free_all(cmds), NULL);
	return (cmds);
}
