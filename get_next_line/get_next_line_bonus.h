/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 17:37:30 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/07/15 17:37:31 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*ft_get_line(char *stash);
char	*ft_get_rest(char *stash);
char	*read_ft(int fd, char *stash);

void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(const char *s, char c);
size_t	ft_strlen(const char *str);
size_t	ft_linelen(const char *str);
char	*ft_strjoin(char *stash, char *buffer);
char	*ft_strpardup(char *s, size_t end);

#endif
