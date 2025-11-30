/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 17:47:29 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/06/08 18:35:23 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_issign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	else
		return (0);
}

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	nbr;

	sign = 1;
	nbr = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (ft_issign(*nptr))
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit((int)*nptr))
	{
		nbr = nbr * 10 + *nptr - 48;
		nptr++;
	}
	nbr = nbr * sign;
	return (nbr);
}
/*
int	main()
{
	char str[] = "123";
	char str1[] = "-123";
	char str2[] = "-+123";
	char str3[] = "1111111111111111";
	char str4[] = "-   123";
	char str5[] = "-123ad5";

	printf("%s: %d\n %s: %d\n %s: %d\n %s: %d\n %s: %d\n%s: %d\n\n", str,
	atoi(str), str1, atoi(str1), str2, atoi(str2), str3, atoi(str3), 
	str4, atoi(str4), str5, atoi(str5));
	printf("%s: %d\n %s: %d\n %s: %d\n %s: %d\n %s: %d\n%s: %d\n", str,
	ft_atoi(str), str1, ft_atoi(str1), str2, ft_atoi(str2), str3, atoi(str3), 
	str4, atoi(str4), str5, atoi(str5));
}
*/
