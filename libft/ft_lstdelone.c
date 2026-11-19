/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_lstdelone.c                                      :+:    :+:           */
/*                                                      +:+                   */
/*   By: mohfall <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/14 10:18:43 by mohfall        #+#    #+#                */
/*   Updated: 2026/10/14 18:54:52 by mohfall        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del (lst->content);
	free (lst);
}
