/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 17:06:39 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/11/16 17:14:24 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if(!lst || !f)
		return (NULL);
	while(lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
