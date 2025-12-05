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

int	set_in_out(char *infile, char *outfile)
{
	int	fd[2];

	fd[0] = open(infile, O_RDONLY);
	if (fd[0] == -1)
		return (-1);
	fd[1] = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[1] == -1)
		return (-1);
	dup2(fd[0], STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	return (0);
}

int	first_cmd(int *child, char *cmd, int pipe_in)
{
	child[0] = fork();
	if (child[0] == -1)
		return (-1);
	if (child[0] == 0)
	{
		dup2(pipe_in, STDOUT_FILENO);
		close(pipe_in);
		free(child);
		execlp(cmd, cmd, NULL);
	}
	close(pipe_in);
	return (0);
}

int	second_cmd(int *child, char *cmd, int pipe_out)
{
	child[1] = fork();
	if (child[1] == -1)
		return (-1);
	if (child[1] == 0)
	{
		dup2(pipe_out, STDIN_FILENO);
		close(pipe_out);
		free(child);
		execlp(cmd, cmd, NULL);
	}
	close(pipe_out);
	return (0);
}

int	main(int argc, char	*argv[], char **envp)
{
	int	fd[2];
	int	*child_id;

	if (argc == 5)
	{
		child_id = malloc(sizeof(int) * 2);
		if (!child_id)
			return (1);
		if (set_in_out(argv[1], argv[4]))
			return (1);
		if (pipe(fd) == -1)
			return (1);
		if (first_cmd(child_id, argv[2], fd[1]) == -1)
			return (1);
		if (second_cmd(child_id, argv[3], fd[0]) == -1)
			return (1);
		waitpid(child_id[0], NULL, 0);
		waitpid(child_id[1], NULL, 0);
		free(child_id);
	}
}
