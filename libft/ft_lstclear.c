/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   ft_lstclear.c                                       :+:    :+:           */
/*                                                      +:+                   */
/*   By: mohfall <marvin@42.fr>                        +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/10/14 10:27:40 by mohfall        #+#    #+#                */
/*   Updated: 2026/10/14 16:39:37 by mohfall        ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;
	t_list	*next_node;

	if (!lst || !*lst || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		next_node = current->next;
		if (del)
			del (current->content);
		free (current);
		current = next_node;
	}
	*lst = NULL;
}
