/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohfall <mohfall@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/01 19:00:47 by mohfall           #+#    #+#             */
/*   Updated: 2026/11/01 19:00:51 by mohfall          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	stack_init(t_node **a, int *tab, int size)
{
	t_node	*node;
	t_node	*last;
	int		i;

	i = 0;
	last = NULL;
	while (i < size)
	{
		node = malloc(sizeof(t_node));
		if (!node)
			return (0);
		node->value = tab[i];
		node->index = 0;
		node->next = 0;
		if (!last)
			*a = node;
		else
			last->next = node;
		last = node;
		i++;
	}
	return (1);
}
