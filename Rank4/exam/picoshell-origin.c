#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int picoshell(char **cmds[])
{
	int		i = 0;
	int		fd[2];
	int		last_fd = -1;
	pid_t	pid;
	int		status;
	int		exit_code = 0;

	// 1. set cmds-loop
	while (cmds[i])
	{
		// 2. if next cmd exit, pipe
		if (cmds[i + 1] && pipe(fd) == -1)
		{
			if (last_fd != -1)
				close(last_fd);
			return (1);
		}
		// 3. fork + error-handling
		pid = fork();
		if (pid == -1)
		{
			if (cmds[i + 1])
			{
				close(fd[0]);
				close(fd[1]);
			}
			if (last_fd != -1)
				close(last_fd);
			return (1);
		}
		// 4. child: piping + exec
		if (pid == 0)
		{
			if (last_fd != -1)
			{
				if (dup2(last_fd, STDIN_FILENO) == -1)
					exit(1);
				close(last_fd);
			}
			if (cmds[i + 1])
			{
				close(fd[0]);
				if (dup2(fd[1], STDOUT_FILENO) == -1)
					exit(1);
				close(fd[1]);
			}
			execvp(cmds[i][0], cmds[i]);
			exit(1);
		}
		// 5. parent: closing + fd parsing
		if (last_fd != -1)
		{
			close(last_fd);
			last_fd = -1;
		}
		if (cmds[i + 1])
		{
			close(fd[1]);
			last_fd = fd[0];
		}
		i++;
	}
	// 6. Clean: close + wait + WIFEXITED() && WEXITSTATUS()
	if (last_fd != -1)
		close(last_fd);
	while (wait(&status) > 0)
	{
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			exit_code = 1;
	}
	return (exit_code);
}
