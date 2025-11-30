/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testpipes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:38:45 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/11/30 19:17:24 by sgavrilo         ###   ########.fr       */
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
void	single_cmd(char *cmd, int cmd_id)
{
	cmd_id = fork();
	if (cmd_id < 0)
		exit(1);
	if (cmd_id == 0)
	{
		execlp(cmd, cmd, NULL);
	}
}
void	mid_cmd(char *cmd, )
{
	if
}

void	last_cmd()
{
}

int	main(int argc, char *argv[])
{
	int		cmd_count = argc - 3;
	int		fd[cmd_count][2];
	int		i;
	char	*cmd[cmd_count];
	int		*cmd_id[cmd_count];

	
	set_in_out(fd[0]);
	i = 0;
	if (cmd_count == 1)
		single_cmd(argv[2], cmd_id[i]);
	if (cmd_count > 1)
	{
	while (i < cmd_count)
	{
		if (i == 0)
		if (pipe(fd[i]) == -1)
			return (100 + i);
		cmd[i] = fork();
		if (cmd[i] < 0)
			return (200 + i);
	if (cmd[i] == 0)
	{
		execlp(argv[1], argv[1], NULL);
	}
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
