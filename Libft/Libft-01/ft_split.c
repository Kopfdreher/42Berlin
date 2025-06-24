/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgavrilo <sgavrilo@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:15:46 by sgavrilo          #+#    #+#             */
/*   Updated: 2025/06/15 14:15:50 by sgavrilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char const *words, char space)
{
	size_t	i;
	size_t	in_word;
	size_t	count;

	i = 0;
	in_word = 0;
	count = 0;
	while (words[i])
	{
		if (words[i] != space && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (words[i] == space && in_word)
			in_word = 0;
		i++;
	}
	return (count);
}

static size_t	ft_word_len(char const *word, char space)
{
	size_t	len;

	len = 0;
	while (word[len] && word[len] != space)
		len++;
	return (len);
}

static void	ft_free_split(char **split, size_t j)
{
	while (j--)
		free(split[j]);
	free(split);
}

static char	**ft_fill_split(char **split, char const *words, char space)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (words[i])
	{
		while (words[i] == space)
			i++;
		if (words[i])
		{
			len = ft_word_len(&words[i], space);
			split[j] = ft_substr(words, i, len);
			if (!split[j])
			{
				ft_free_split(split, j);
				return (NULL);
			}
			i += len;
			j++;
		}
	}
	split[j] = NULL;
	return (split);
}

char	**ft_split(char const *words, char space)
{
	char	**split;
	size_t	count;

	if (!words)
		return (NULL);
	count = ft_word_count(words, space);
	split = malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	return (ft_fill_split(split, words, space)); 
}
