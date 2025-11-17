/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:06:30 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/11/16 16:27:46 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_lstsize(t_list *lst)
{
	int	size;

	if (!lst)
		return (NULL);
	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}
