/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_strjoin.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: mohfall <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/11 14:45:50 by mohfall        #+#    #+#                */
/*   Updated: 2026/10/14 18:39:15 by mohfall        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l1;
	size_t	l2;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	res = malloc(l1 + l2 + 1);
	if (!res)
		return (NULL);
	ft_memcpy(res, s1, l1);
	ft_memcpy(res + l1, s2, l2);
	res[l1 + l2] = '\0';
	return (res);
}
