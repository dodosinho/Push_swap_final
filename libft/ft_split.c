/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_split.c                                          :+:    :+:           */
/*                                                      +:+                   */
/*   By: mohfall <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/11 16:53:26 by mohfall        #+#    #+#                */
/*   Updated: 2026/10/12 15:16:07 by mohfall        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	size_t	count_words(char const *s, char c)
{
	size_t	n;

	n = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			n++;
		while (*s && *s != c)
			s++;
	}
	return (n);
}

static	size_t	word_len(char const *s, char c)
{
	size_t	n;

	n = 0;
	while (s[n] && s[n] != c)
		n++;
	return (n);
}

static	void	*free_all(char **arr, size_t i)
{
	while (i--)
		free (arr[i]);
	free (arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	i;
	size_t	len;

	if (!s)
		return (NULL);
	arr = malloc(sizeof (char *) *(count_words(s, c) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = word_len(s, c);
			arr[i] = ft_substr(s, 0, len);
			if (!arr[i++])
				return (free_all(arr, i - 1));
			s += len;
		}
		else
			s++;
	}
	arr[i] = NULL;
	return (arr);
}
