/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 11:41:02 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/11/20 13:08:59 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_error();

int	main(int argc, char *argv[])
{
	if (argc < 3 || input_has_errors(argc, argv))
		ft_error();
}

void	ft_error()
{
	ft_printf("%s", "Error\n");
	exit(0);
}
