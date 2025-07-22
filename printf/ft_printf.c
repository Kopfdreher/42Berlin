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

#include <unistd.h>
#include <stdarg.h>

size_t	ft_strlen(const	char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	put_char(char c)
{
	write(1, &c, 1);
}

void	put_string(char *str)
{
	write(1, str, ft_strlen(str));
}

int		is_print(char c)
{
	return (c >= 32 && c <= 126);
}

void	check_format(const char *format, va_list args)
{
	if (format[1] && format[1] == 'c')
			put_char(va_arg(args, int));
	if (format[1] && format[1] == 's')
			put_string(va_arg(args,char *));
	/*
	if (format[1] && format[1] == 'p')
			put_voidp(va_arg(args, void *));
	if (format[1] && format[1] == 'd')
			put_decimal_num(va_arg(args, char *));
	if (format[1] && format[1] == 'i')
			put_int(va_arg(args, char *));
	if (format[1] && format[1] == 'u')
			put_unsigned_int(va_arg(args, char *));
	if (format[1] && format[1] == 'x')
			put_hexdec_num_low(va_arg(args, char *));
	if (format[1] && format[1] == 'X')
			put_hexdec_num_high(va_arg(args, char *));
	*/
	if (format[1] && format[1] == '%')
			put_char(format[1]);
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


int	main(void)
{
	char	hello[] = "Hello";
	char	world[] = "World";

	ft_printf("%s %s!", hello, world);
}
