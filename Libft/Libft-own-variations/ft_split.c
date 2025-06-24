/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 12:05:02 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/06/15 12:05:05 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*   split - returns splitted array of ’s’ using ’c’ as a delimiter           */

size_t	ft_pos_count(char const *s, char c)
{
	size_t	pos_len;

	pos_len = 2;	// 2 extra positions for the start and end
	while (s)
	{
		if (*s == c)
			pos_len++;
		s++;
	}
	return (pos_len);
}

size_t	*ft_position(char const *s, char c)
{
	size_t	i;
	size_t	count;
	int	position[ft_pos_count(s, c)];
	
	i = 0;
	count = 0;
	position[0] = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			position[count] = i;
			count++;
		}
		i++;
	}
	position[count] = i; 
	return (position);
}


char	**ft_split(char const *s, char c)
{
	int	*position;
	size_t	pos_count;
	size_t	i;
	char	*split[pos_count -1];

	pos_count = ft_pos_count(s, c);
	position = ft_position(s, c);
	i = 0;
	while (i < pos_count - 1)
	{
		split[i] = ft_substr(s, position[i], position[i + 1]);
		if (!split[i])
			return (NULL);
		i++;
	}
	return (split);
}
