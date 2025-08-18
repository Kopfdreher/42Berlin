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

static int	check_format(const char *format, va_list args, int output_len)
{
	format++;
	if (*format == 'c')
		output_len += put_char(va_arg(args, int));
	else if (*format == 's')
		output_len += put_string(va_arg(args, char *));
	else if (*format == 'i' || *format == 'd')
		output_len += put_int(va_arg(args, int));
	else if (*format == 'u')
		output_len += put_unsigned_int(va_arg(args, unsigned int));
	else if (*format == 'x' || *format == 'X' || *format == 'p')
		output_len += put_hex(va_arg(args, unsigned long), *format);
	else if (*format == '%')
		output_len += put_char('%');
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
	if (!format)
		return (-1);
	va_start(args, format);
	format_len = ft_strlen(format);
	i = -1;
	while (++i < format_len)
	{
		if (format[i] == '%')
		{
			output_len += check_format(&format[i], args, 0);
			i += 1;
		}
		else
			output_len += put_char(format[i]);
	}
	va_end(args);
	return (output_len);
}
