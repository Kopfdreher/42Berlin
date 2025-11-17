/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:15:18 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/11/16 17:57:21 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list	*ft_lstmap(t_list *lst, void (*f)(void *), void (*del)(void *))
{
	if (!lst || !f || !del)
		return (NULL);
	if (!f(lst->content))
		-
	else
		del(lst->content);
}
