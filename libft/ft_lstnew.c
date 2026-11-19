/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_lstnew.c                                         :+:    :+:           */
/*                                                      +:+                   */
/*   By: mohfall <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/13 17:29:09 by mohfall        #+#    #+#                */
/*   Updated: 2026/10/14 18:09:15 by mohfall        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
