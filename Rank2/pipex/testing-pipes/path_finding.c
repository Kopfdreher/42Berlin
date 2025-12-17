/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:34:01 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/10 17:41:58 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

static char	*create_path(char *path, char *cmd)
{
	char	*exec_path;
	char	*tmp;

	tmp = ft_strjoin(path, "/");
	exec_path = ft_strjoin(tmp, cmd);
	free(tmp);
	return (exec_path);
}

static int	access_path(char *path)
{
	if (access(path, F_OK | X_OK))
	{
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		return (1);
	}
	return (0);
}

static char	*cmd_is_path(char *cmd, int *error)
{
	char	*exec_path;

	exec_path = ft_strdup(cmd);
	if (access_path(exec_path))
	{
		*error = 1;
		return (free(exec_path), NULL);
	}
	return (exec_path);
}

static void	cmd_not_found(char *cmd, int *error)
{
	*error = 127;
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd(": command not found\n", 2);
}

char	*path_finding(char *cmd, char **envp, int *error)
{
	int		i;
	char	**paths;
	char	*exec_path;

	if (!cmd)
		return (ft_putstr_fd("pipex: Permission denied:\n", 2), NULL);
	if (cmd[0] == '/')
		return (cmd_is_path(cmd, error));
	i = 0;
	while (!ft_strnstr(envp[i], "PATH=", 5))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	exec_path = create_path(paths[i], cmd); 
	while (paths[i] && access(exec_path, F_OK | X_OK))
	{
		free(exec_path);
		exec_path = create_path(paths[i], cmd);
		i++;
	}
	free_split(paths);
	if (access(exec_path, F_OK | X_OK))
		return (cmd_not_found(cmd, error), free(exec_path), NULL);
	return (exec_path);
}
