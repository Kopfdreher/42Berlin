/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarrcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 19:13:50 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/13 20:11:06 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strarrcpy(char **strarr)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (ft_strarrlen(strarr) + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (strarr[i])
	{
		copy[i] = ft_strdup(strarr[i]);
		if (!copy[i])
			return (free_strarr(copy), NULL);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
