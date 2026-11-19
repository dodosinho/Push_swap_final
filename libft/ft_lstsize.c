/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_lstsize.c                                        :+:    :+:           */
/*                                                      +:+                   */
/*   By: mohfall <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/13 18:45:25 by mohfall        #+#    #+#                */
/*   Updated: 2026/10/14 19:38:10 by mohfall        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	unsigned int	n;

	n = 0;
	while (lst)
	{
		n++;
		lst = lst->next;
	}
	return (n);
}
