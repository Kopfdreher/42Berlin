/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:20:41 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/10 16:38:00 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>

typedef struct s_cmds
{
	char	*infile;
	char	*outfile;
	int		in_fd;
	int		out_fd;
	char	**value[2];
	char	**envp;
	int		id[2];
	int		fd[2];
	int		error;
}	t_cmds;

char	*path_finding(char *cmd, char **envp, int *error);
void	free_all(t_cmds *cmds);
void	close_all(t_cmds *cmds);
t_cmds	*initialize(t_cmds *cmds, char **argv, char **envp);
void	file_err(char *file, int *error);

#endif
