/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_substr.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: mohfall <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/11 14:07:12 by mohfall        #+#    #+#                */
/*   Updated: 2026/10/14 15:32:03 by mohfall        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
//#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	slen;
	char	*sub;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		return (ft_strdup(""));
	if (len > slen - start)
		len = slen - start;
	sub = malloc(len + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	sub[len] = '\0';
	return (sub);
}

/*int main(void)
{	
	printf("%s\n",ft_substr("BONJOUR LES HARICOTS !", 8, 14));
	return (0);
}*/
