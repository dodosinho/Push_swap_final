/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_memchr.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: mohfall <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/08 16:57:04 by mohfall        #+#    #+#                */
/*   Updated: 2026/10/12 15:52:59 by mohfall        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p;

	p = (const unsigned char *)s;
	while (n--)
	{
		if (*p == (unsigned char)c)
			return ((void *)p);
		p++;
	}
	return (NULL);
}
