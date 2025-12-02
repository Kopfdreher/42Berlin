/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testpipes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:38:45 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/02 16:56:58 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>

void	set_in_out(int fd[2])
{
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	dup2(fd[0][0], STDIN_FILENO);
	dup2(fd[0][1], STDOUT_FILENO);
	close(fd[0][0]);
	close(fd[0][1]);
}

void	first_cmd(char *cmd_arg, int *pipe[2])
{
	int	cmd_id;

	if (pipe(*pipe) == -1)
		return (100);
	cmd_id = fork();
	if (cmd_id < 0)
		return (200);
	if (cmd_id == 0)
	{
		dup2(*pipe[1], STDOUT_FILENO);
		close(*pipe[1]);
		execlp(cmd_arg, cmd_arg, NULL);
	}
}

void	mid_cmd(char *cmd_arg, int *pipe_a[2], int *pipe_b[2])
{
	int	cmd_id;

	if (pipe(*pipe_b) == -1)
		return (100);
	cmd_id = fork();
	if (cmd_id < 0)
		return (200);
	if (cmd_id == 0)
	{
		dup2(*pipe_a[0], STDIN_FILENO);
		close(*pipe_a[0]);
		dup2(*pipe_b[1], STDOUT_FILENO);
		close(*pipe_b[1]);
		execlp(cmd_arg, cmd_arg, NULL);
}

void	last_cmd()
{
}

int	main(int argc, char *argv[])
{
	int		cmd_count = argc - 3;
	int		fd[cmd_count][2];
	int		i;
	char	*cmd_arg[cmd_count];

	if (get_cmd_count(argc, argv))
		return (1);
	set_in_out(fd[0]);
	i = 0;
	if (cmd_count > 1)
	{
		while (i < cmd_count)
		{
			if (i == 0)
				first_cmd(cmd_arg[i], &fd[i]);
			else if (
			else
				middle_cmd(cmd_arg[i], &fd[i-1], &fd[i]);
		}
	}
	close(pipe_a[0]);
	close(pipe_a[1]);
	close(pipe_b[0]);
	close(pipe_b[1]);
	waitpid(id, NULL, 0);
	waitpid(pid2, NULL, 0);
	waitpid(pid3, NULL, 0);
	return (0);
}
