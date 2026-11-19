/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_strdup.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: mohfall <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/10 17:06:51 by mohfall        #+#    #+#                */
/*   Updated: 2026/10/10 17:31:37 by mohfall        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*d;

	len = ft_strlen(s) + 1;
	d = malloc(len);
	if (!d)
		return (NULL);
	ft_memcpy(d, s, len);
	return (d);
}
