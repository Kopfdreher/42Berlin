/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:55:59 by sgavrilo          #+#    #+#             */
/*   Updated: 2026/01/04 11:49:49 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int	i;

	i = -1;
	while (argv[++i])
		printf("%s\n", argv[i]);
}
