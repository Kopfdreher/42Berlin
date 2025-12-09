/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 15:20:41 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/09 14:42:42 by sgavrilo         ###   ########.fr       */
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
	char	**value[2];
	char	**envp;
	int		id;
	int		fd[2];
} t_cmds;

char	*path_finding(char *cmd, char **envp);
void	free_all(t_cmds *cmds);

#endif
