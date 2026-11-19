/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_memcpy.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: mohfall <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/08 11:27:49 by mohfall        #+#    #+#                */
/*   Updated: 2026/10/12 15:46:59 by mohfall        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dst);
}
