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

#ifndef PRINTF_H
# define PRINTF_H
# include <unistd.h>
# include <stdarg.h>

size_t	ft_strlen(const	char *str);
void	put_char(char c);
void	put_string(char *str);
void	ft_printf(const char *format, ...);

#endif
