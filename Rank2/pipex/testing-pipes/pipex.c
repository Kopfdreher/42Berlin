/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:10:08 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/09 18:32:28 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

static int	first_cmd(t_cmds *cmds)
{
	char	*path;
	int		fd_in;

	fd_in = open(cmds->infile, O_RDONLY);
	if (fd_in == -1)
		return(perror("pipex"), close(cmds->fd[1]), -1);
	path = path_finding(*cmds->value[0], cmds->envp);
	if (!path)
		return (free(path), -1);
	cmds->id[0] = fork();
	if (cmds->id[0] == -1)
		return (free(path), -1);
	if (cmds->id[0] == 0)
	{
		if (dup2(cmds->fd[1], STDOUT_FILENO) == -1)
			return(free(path), perror("pipex"), -1);
		close(cmds->fd[1]);
		close(cmds->fd[0]);
		execve(path, cmds->value[0], NULL);
	}
	close(cmds->fd[1]);
	return (free(path), 0);
}

static int	second_cmd(t_cmds *cmds)
{
	char	*path;
	int		fd_out;

	fd_out = open(cmds->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1)
		return(perror("pipex"), -1);
	path = path_finding(*cmds->value[1], cmds->envp);
	if (!path)
		return (free(path), -1);
	cmds->id[1] = fork();
	if (cmds->id[1] == -1)
		return (free(path), -1);
	if (cmds->id[1] == 0)
	{
		if (dup2(cmds->fd[0], STDIN_FILENO) == -1)
			return(free(path), perror("pipex"), -1);
		close(cmds->fd[0]);
		close(cmds->fd[1]);
		execve(path, cmds->value[1], NULL);
	}
	close(cmds->fd[0]);
	return (free(path), 0);
}

int	main(int argc, char *argv[], char **envp)
{
	t_cmds	*cmds;

	if (argc == 5)
	{
		cmds = NULL;
		if (initialize(cmds, argv, envp))
			return (1);
		if (first_cmd(cmds))
			close(cmds->fd[0]);
		if (second_cmd(cmds))
			return (1);
		waitpid(cmds->id[0], NULL, 0);
		waitpid(cmds->id[1], NULL, 0);
		free_all(cmds);
	}
	return (0);
}
