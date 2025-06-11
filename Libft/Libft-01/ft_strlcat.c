/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 15:32:46 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/06/03 19:13:04 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlcat(char *dst, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	start;

	i = 0;
	start = 0;
	while (dst[start++] != 0)
	{
	}
	while (i + start < size && i + start < sizeof (dst))
		dst[start + i] = src[i++];
	return (dst);
}
/*
int	main(void)
{
	char	src[] = "World";
	char	dst[11];
	int	i = 0;

	while(i < 11)
		dst[i++] = 0;
	dst[0] = 'H';
	dst[1] = 'e';
	dst[2] = 'l';
	dst[3] = 'l';
	dst[4] = 'o';
	dst[5] = ' ';
	ft_strlcat(dst, src, 11);
}
*/
