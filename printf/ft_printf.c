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

int	is_print(char c)
{
	return (c >= 32 && c <= 126);
}

int	check_format(const char *format, va_list args, int output_len)
{
	format++;
	switch (*format) {
		case 'c':
			output_len += put_char(va_arg(args, int));
			break;
		case 's':
			output_len += put_string(va_arg(args, char *));
			break;
		case 'i':
		case 'd':
			output_len += put_int(va_arg(args, int));
			break;
		case 'u':
			output_len += put_unsigned_int(va_arg(args, unsigned int));
			break;
		case 'x':
		case 'X':
		case 'p':
			output_len += put_hex(va_arg(args, unsigned long), *format);
			break;
		case '%':
			output_len += put_char('%');
	}
	return (output_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*str;
	int		i;
	int		format_len;
	int		output_len;

	output_len = 0;
	va_start(args, format);
	format_len = ft_strlen(format);
	i = -1;
	while (++i < format_len)
	{
		if (format[i] == '%')
		{
			output_len += check_format(&format[i], args, 0);
			i += 2;
		}
		if (is_print(format[i]))
			output_len += put_char(format[i]);
	}
	va_end(args);
	return (output_len);
}
