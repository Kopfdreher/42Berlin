/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 17:58:39 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/07/22 17:58:41 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const	char *str);
int		put_char(char c);
int		put_string(char *str);
int		put_int(int n);
int		put_unsigned_int(unsigned int u);
int		put_hex(unsigned long hex, char x);

#endif
