/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testpipes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 18:38:45 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/10 15:15:35 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>

int	main(int argc, char *argv[])
{
	int	pipe_a[2];
	int	pipe_b[2];
	int	pipe[][];
	int	prev_fd;
	int	pid1;
	int	pid2;
	int	pid3;

	if (pipe(pipe_a) == -1)
		return (1);
	pid1 = fork();
	if (pid1 < 0)
		return (2);
	if (pid1 == 0)
	{
		dup2(pipe_a[1], STDOUT_FILENO);
		close(pipe_a[0]);
		close(pipe_a[1]);
		execlp(argv[1], argv[1], NULL);
	}
	if (pipe(pipe_b) == -1)
		return (3);
	pid2 = fork();
	if (pid2 < 0)
		return (4);
	if (pid2 == 0)
	{
		dup2(pipe_a[0], STDIN_FILENO);
		dup2(pipe_b[1], STDOUT_FILENO);
		close(pipe_a[0]);
		close(pipe_a[1]);
		close(pipe_b[0]);
		close(pipe_b[1]);
		execlp(argv[2], argv[2], NULL);
	}
	close(pipe_a[0]);
	close(pipe_a[1]);
	pid3 = fork();
	if (pid3 < 0)
		return (4);
	if (pid3 == 0) //
	{
		dup2(pipe_b[0], STDIN_FILENO);
		close(pipe_b[0]);
		close(pipe_b[1]);
		execlp(argv[3], argv[3], NULL);
	}
	close(pipe_a[0]);
	close(pipe_a[1]);
	close(pipe_b[0]);
	close(pipe_b[1]);

	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	waitpid(pid3, NULL, 0);
	return (0);
}
