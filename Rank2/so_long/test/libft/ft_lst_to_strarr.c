/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_strarr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 16:48:55 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/12/13 16:49:11 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_lst_to_strarr(t_list **lst)
{
	int		lst_size;
	t_list	*next;
	int		i;
	char	**strarr;

	lst_size = ft_lstsize(*lst);
	strarr = malloc(sizeof(char *) * (lst_size + 1));
	if (!strarr)
		return (ft_lstclear(lst, free), NULL);
	i = 0;
	while (*lst)
	{
		next = (*lst)->next;
		strarr[i] = (*lst)->content;
		free(*lst);
		*lst = next;
		i++;
	}
	strarr[i] = NULL;
	return (strarr);
}
