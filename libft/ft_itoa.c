/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_itoa.c                                           :+:    :+:           */
/*                                                      +:+                   */
/*   By: mohfall <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/12 15:56:14 by mohfall        #+#    #+#                */
/*   Updated: 2026/10/14 11:23:35 by mohfall        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	size_t	num_len(long n)
{
	size_t	len;

	len = (n <= 0);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	size_t	len;
	char	*str;

	nb = n;
	len = num_len(nb);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
		nb = -nb;
	while (len--)
	{
		str[len] = nb % 10 + '0';
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
