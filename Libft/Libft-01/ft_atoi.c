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

#include <stdio.h>
#include <stdlib.h>

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_issign_orspace(char c)
{
	if (c == ' ' || c == '+' || c == '-')
		return (1);
	else
		return (0);
}

int	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	nbr;
	int	i;
	int 	len;

	i = 0;
	sign = 0;
	nbr = 0;
	len = ft_strlen(nptr);
	while (i < len)
	{		
		if (!ft_isdigit(nptr[i]) && nbr)
			return (nbr);
		if (ft_issign_orspace(nptr[i]) && sign)
			return (nbr);
		if (nptr[i] == '+' && !(sign))
			sign = 1;
		if (nptr[i] == '-' && !(sign))
			sign = -1;
		if (ft_isdigit(nptr[i]))
		{
			nbr = nbr * 10 + nptr[i] - 48;
		}
		else
			return (nbr);
		i++;	
	}
	return (nbr);
}


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
