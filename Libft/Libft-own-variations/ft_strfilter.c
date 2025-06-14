/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 11:04:23 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/06/14 11:04:25 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   strfilter - Deletes all appearances of set in s1 and creates a n_s1      */

#include <stdlib.h>

char	*ft_strfilter(char const *s1, char const *set)
{
	char	*n_s1;		// new s1
	char	*s1_1;		// s1 first-part
	char	*s1_2;		// s1 second-part

	s1_2 = ft_strnstr(s1, set, ft_strlen(set))
	s1_1 = substr(s1, 0, ft_strlen(s1) - ft_strlen(s1_2));
	n_s1 = ft_strjoin(s1_1, s1_2);
	free (s1_1);
	if (!strnstr(n_s1, set, ft_strlen(set)))
		n_s1 = strdup(n_s1);
		return(n_s1);
	else
		n_s1 = ft_strfilter(n_s1, set);
}
