/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohfall <mohfall@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 19:01:21 by mohfall           #+#    #+#             */
/*   Updated: 2026/11/06 15:13:31 by mohfall          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_sorted(t_node *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int	count_nodes(t_node *a)
{
	int	n;

	n = 0;
	while (a)
	{
		n++;
		a = a->next;
	}
	return (n);
}

void	free_stack(t_node **s)
{
	t_node	*tmp;

	while (*s)
	{
		tmp = (*s)->next;
		free(*s);
		*s = tmp;
	}
}
