/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 22:18:52 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/27 12:39:23 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_issign(char c)
{
	return (c == '+' || c == '-');
}

static int	ft_isspace(char c)
{
	return (c == '0' || c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

static int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

long	ft_atol(const char *str)
{
	long	nbr;
	int		sign;
	int		i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (ft_issign(str[i]))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit((int)str[i]))
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}
