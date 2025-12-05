/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:34:01 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/05 20:03:19 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft.h"

char	*create_path(char *path, char *cmd)
{
	char	*exec_path;
	char	*tmp;

	tmp = ft_strjoin(path, "/");
	exec_path = ft_strjoin(tmp, cmd);
	free(tmp);
	return (exec_path);
}

char	*path_finding(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*exec_path;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH=", 5))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	exec_path = create_path(paths[i], cmd); 
	while (paths[i] && access(exec_path, F_OK | X_OK))
	{
		i++;
		free(exec_path);
		exec_path = create_path(paths[i], cmd); 
	}
	free_split(paths);
	if (access(exec_path, F_OK | X_OK))
	{
		free(exec_path);
		return (NULL);
	}
	return (exec_path);
}
