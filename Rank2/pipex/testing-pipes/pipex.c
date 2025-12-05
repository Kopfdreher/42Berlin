/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two-pipes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 13:10:08 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/05 13:10:08 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

static int	set_in_out(char *infile, char *outfile)
{
	int	fd[2];

	fd[0] = open(infile, O_RDONLY);
	if (fd[0] == -1)
		perror("pipex");
	fd[1] = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[1] == -1)
		perror("pipex");
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	return (0);
}

static int	first_cmd(char *infile, int *child, char **cmd, int fd[2], char **envp)
{
	char	*path;
	int		fd_in;

	fd_in = open(infile, O_RDONLY);
	if (fd_in == -1)
		return(perror("pipex"), close(fd[1]), -1);
	path = path_finding(cmd[0], envp);
	if (!path)
		return (free(path), -1);
	child[0] = fork();
	if (child[0] == -1)
		return (free(path), -1);
	if (child[0] == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		close(fd[0]);
		free(child);
		execve(path, cmd, NULL);
	}
	close(fd[1]);
	return (free(path), 0);
}

static int	second_cmd(int *child, char **cmd, int fd[2], char **envp)
{
	char	*path;
	int		fd_out;

	fd_out = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_out == -1)
		return(perror("pipex"), -1);
	path = path_finding(cmd[0], envp);
	if (!path)
		return (free(path), -1);
	child[1] = fork();
	if (child[1] == -1)
		return (free(path), -1);
	if (child[1] == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		free(child);
		execve(path, cmd, NULL);
	}
	close(fd[0]);
	return (free(path), 0);
}

int	main(int argc, char	*argv[], char **envp)
{
	int		fd[2];
	int		*child_id;
	char	**cmds[2];

	if (argc == 5)
	{
		cmds[0] = ft_split(argv[2], ' ');
		cmds[1] = ft_split(argv[3], ' ');
		child_id = malloc(sizeof(int) * 2);
		if (!child_id)
			return (free(cmds[0]), free(cmds[1]), 1);
		if (pipe(fd) == -1)
			return (free(cmds[0]), free(cmds[1]), free(child_id), 1);
		if (first_cmd(argv[1], child_id, cmds[0], fd, envp) == -1)
			close(fd[0]);
		if (second_cmd(child_id, cmds[1], fd, envp) == -1)
			return (1);
		waitpid(child_id[0], NULL, 0);
		waitpid(child_id[1], NULL, 0);
		free(child_id);
		free_split(cmds[0]);
		free_split(cmds[1]);
	}
}
