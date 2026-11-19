/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_lstadd_front.c                                   :+:    :+:           */
/*                                                      +:+                   */
/*   By: mohfall <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/13 18:16:12 by mohfall        #+#    #+#                */
/*   Updated: 2026/10/14 09:57:29 by mohfall        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
