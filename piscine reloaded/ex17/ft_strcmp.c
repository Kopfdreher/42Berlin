/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:33:34 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/05/11 13:44:09 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' &&  s1[i] == s2[i])
		i++;
	return(s1[i] - s2[i]);
}
/*
int	main(void)
{
	char s1[] = "\0";
	char s2[] = "";

	printf("strcmp:		%d\nft_strcmp	%d\n", strcmp(s1, s2), ft_strcmp(s1, s2));
}
*/
