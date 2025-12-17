/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:10:08 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/10 17:42:48 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

static int	first_cmd(t_cmds *cmds)
{
	char	*path;

	path = path_finding(*cmds->value[0], cmds->envp, &cmds->error);
	if (!path)
		return (free(path), close(cmds->fd[1]), -1);
	cmds->in_fd = open(cmds->infile, O_RDONLY);
	if (cmds->in_fd == -1)
		return (free(path), file_err(cmds->infile, &cmds->error),
			close(cmds->fd[1]), -1);
	cmds->id[0] = fork();
	if (cmds->id[0] == -1)
		return (free(path), close(cmds->fd[1]), -1);
	if (cmds->id[0] == 0)
	{
		dup2(cmds->fd[1], STDOUT_FILENO);
		dup2(cmds->in_fd, STDIN_FILENO);
		close_all(cmds);
		execve(path, cmds->value[0], NULL);
	}
	close(cmds->fd[1]);
	close(cmds->in_fd);
	return (free(path), 0);
}

static int	second_cmd(t_cmds *cmds)
{
	char	*path;

	path = path_finding(*cmds->value[1], cmds->envp, &cmds->error);
	if (!path)
		return (free(path), close(cmds->fd[0]), -1);
	cmds->id[1] = fork();
	if (cmds->id[1] == -1)
		return (free(path), close(cmds->fd[0]), -1);
	if (cmds->id[1] == 0)
	{
		dup2(cmds->fd[0], STDIN_FILENO);
		dup2(cmds->out_fd, STDOUT_FILENO);
		close_all(cmds);
		execve(path, cmds->value[1], NULL);
	}
	close(cmds->fd[0]);
	close(cmds->out_fd);
	return (free(path), 0);
}

int	main(int argc, char *argv[], char **envp)
{
	t_cmds	*cmds;
	int		error;

	error = 0;
	if (argc == 5)
	{
		cmds = NULL;
		cmds = initialize(cmds, argv, envp);
		if (!cmds)
			return (1);
		if (first_cmd(cmds))
			error = cmds->error;
		if (second_cmd(cmds))
			error = cmds->error;
		waitpid(cmds->id[0], NULL, 0);
		waitpid(cmds->id[1], NULL, 0);
		free_all(cmds);
	}
	return (error);
}
