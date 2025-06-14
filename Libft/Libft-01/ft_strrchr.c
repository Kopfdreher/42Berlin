/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 17:59:46 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/06/03 19:17:01 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   strrchr - String Character Search (points to the last accurance)         */

char	*ft_strrchr(const char *s, char c)
{
	const char	*ptr;
	const char	*save;

	ptr = s;
	save = s;
	while (*ptr != 0)
	{
		if (*ptr == c)
			save = ptr;
		ptr++;
	}
	if (*save == c)
		return ((char *)save);
	else
		return (0);
}
