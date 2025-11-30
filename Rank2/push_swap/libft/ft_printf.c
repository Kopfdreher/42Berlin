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

#include "libft.h"

static int	print_check_format(const char format, va_list args)
{
	if (!format)
		return (0);
	if (format == 'c')
		return (print_put_char(va_arg(args, int)));
	if (format == 's')
		return (print_put_string(va_arg(args, char *)));
	if (format == 'i' || format == 'd')
		return (print_put_int(va_arg(args, int)));
	if (format == 'u')
		return (print_put_unsigned_int(va_arg(args, unsigned int)));
	if (format == 'x' || format == 'X')
		return (print_put_hex(va_arg(args, unsigned int), format));
	if (format == 'p')
		return (print_put_hex(va_arg(args, unsigned long), format));
	if (format == '%')
		return (print_put_char('%'));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		written;

	if (!format)
		return (-1);
	va_start(args, format);
	i = -1;
	written = 0;
	while (format[++i] && written != -1)
	{
		if (format[i] == '%')
			written += print_check_format(format[++i], args);
		else
			written += print_put_char(format[i]);
	}
	return (va_end(args), written);
}
