/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agarcia2 <agarcia2@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 23:47:36 by rmarin-n          #+#    #+#             */
/*   Updated: 2026/03/24 10:35:27 by agarcia2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			count++;
			while (*s && *s != c)
				s++;
		}
	}
	return (count);
}

char	**add_word(char **dest, char const **s, char c)
{
	char	*start;

	while (**s && **s == c)
		(*s)++;
	if (**s)
	{
		start = (char *)*s;
		while (**s && **s != c)
			(*s)++;
		*dest = ft_substr(start, 0, *s - start);
		if (!*dest)
			return (NULL);
		dest++;
	}
	return (dest);
}

char	**free_split(char **arr)
{
	char	**tmp;

	tmp = arr;
	while (*tmp)
		free(*tmp++);
	free(arr);
	arr = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	char	**ptr;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(*arr) * (count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	ptr = arr;
	while (*s)
	{
		ptr = add_word(ptr, &s, c);
		if (!ptr)
			return (free_split(arr));
	}
	*ptr = NULL;
	return (arr);
}
