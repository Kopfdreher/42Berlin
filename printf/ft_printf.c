/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:51:57 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/07/21 18:51:58 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const	char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	is_print(char c)
{
	return (c >= 32 && c <= 126);
}

void	check_format(const char *format, va_list args)
{
	format++;
	switch (*format) {
		case 'c':
			put_char(va_arg(args, int));
		case 's':
			put_string(va_arg(args,char *));
/*
		case 'p':
			put_voidp(va_arg(args, void *));
		case 'd':
			put_decimal_num(va_arg(args, char *));
		case 'i':
			put_int(va_arg(args, char *));
		case 'u':
			put_unsigned_int(va_arg(args, char *));
		case 'x':
			put_hexdec_num_low(va_arg(args, char *));
		case 'X':
			put_hexdec_num_high(va_arg(args, char *));
*/
		case '%':
			put_char('%');
	}
}

void	ft_printf(const char *format, ...)
{
	va_list		args;
	char		*str;
	static int	i;
	int			format_len;

	va_start(args, format);
	format_len = ft_strlen(format);
	i = -1;
	while (++i < format_len)
	{
		if (format[i] == '%')
		{
			check_format(format, args);
			i += 2;
		}
		if (is_print(format[i]))
			put_char(format[i]);
	}
	va_end(args);
}
