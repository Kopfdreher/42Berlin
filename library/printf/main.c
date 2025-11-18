/* ************************************************************************** */
/*                                                                            */ /*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 19:10:37 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/08/18 19:10:38 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	main()
{
	int	n = INT_MAX;
	unsigned int	*ptr = &n;
	unsigned int	*nullptr = NULL;
	char			*str = "Hello World";
	char			*emptystr = "";
	char			*nullstr = NULL;

	ft_printf("\nft_printf-Return-Value: %i\n", 
		   ft_printf("\n***FTPRINTF***\nNull-Terminator: %c\nSimple-String: %s\nEmpty-String: %s\nNull-String: %s\nPointer: %p\nNull-Pointer: %p\nDecimal-Number: %d\nInteger: %i\nUnsigned Integer: %u\nHexadecimal Lowercase: %x\nHexadecimal Uppercase: %X\nPercent-Sign: %%", '\0', str, emptystr, nullstr, ptr, nullptr, n, n, n, n, n));
	printf("\nprintf-Return-Value: %i\n", 
			printf("\n*** PRINTF ***\nNull-Terminator: %c\nSimple-String: %s\nEmpty-String: %s\nNull-String: %s\nPointer: %p\nNull-Pointer: %p\nDecimal-Number: %d\nInteger: %i\nUnsigned Integer: %u\nHexadecimal Lowercase: %x\nHexadecimal Uppercase: %X\nPercent-Sign: %%", '\0', str, emptystr, nullstr, ptr, nullptr, n, n, n, n, n));
	fprintf(stderr, 
		 	"\n***NULL-Return***" 
		 	"\nprintf(NULL) = %i" 
		 	"\nft_printf(NULL) = %i" 
		 	"\n", 
		 	printf(NULL), ft_printf(NULL));
	fclose(stdout);
	fprintf(stderr,
		 	"\n***Closed-STDOUT-Return***" 
		 	"\nprintf(test) = %i" 
		 	"\nft_printf(test) = %i" 
		 	"\n", 
		 	printf("test"), ft_printf("test"));
}
