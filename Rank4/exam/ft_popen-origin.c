#include <unistd.h>
#include <stdlib.h>

int	ft_popen(const char *file, char *const argv[], char type)
{
	int fd[2];
	pid_t pid;

	// 1. Parameter Validation
	// The subject requires returning -1 on invalid parameters.
	if (!file || !argv || (type != 'r' && type != 'w'))
		return (-1);

	// 2. Create the pipe
	if (pipe(fd) == -1)
		return (-1);

	// 3. Fork the process
	pid = fork();
	if (pid == -1)
	{
		// TRAP 1: If fork fails, you MUST close the pipe before returning,
		// otherwise you leak file descriptors.
		close(fd[0]);
		close(fd[1]);
		return (-1);
	}

	if (pid == 0) // --- Child-Process ---
	{
		if (type == 'r')
		{
			if (dup2(fd[1], STDOUT_FILENO) == -1)
				exit(1);
		}
		else // type == 'w'
		{
			if (dup2(fd[0], STDIN_FILENO) == -1)
				exit(1);
		}
		close(fd[0]);
		close(fd[1]);
		execvp(file, argv);
		exit(1);
	}

	// --- Parent-Process ---
	if (type == 'r')
	{
		close(fd[1]);
		return (fd[0]);
	}
	else // type == 'w'
	{
		close(fd[0]);
		return (fd[1]);
	}
}
